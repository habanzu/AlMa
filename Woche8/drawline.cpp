#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>



void draw_line(const double px1, const double py1, const double px2, const double py2, const double thickness, const uint8_t color, uint8_t* image, const unsigned int WIDTH, const unsigned int HEIGHT) {
    // Die Punkte (px1,py1) und (px2,py2) sind reelle Koordinaten im Bild-Koordinatensystem. Der Ursprung liegt in der unteren linken Ecke des Bildes.
    // Der Parameter thickness gibt die Linienstärke in Pixeln an.
    // Der Parameter color ist ein Graustufenwert zwischen 0 und 255 und gibt die Linienfarbe an.
    // image ist ein Zeiger auf das Bild-Array, in das geschrieben wird. Bitte beachten, dass ein eindimensionales Array der Länge WIDTH*HEIGHT übergeben werden muss.
    // WIDTH und HEIGHT geben die Pixelmaße des Bild-Arrays an.
    
    // Do nothing if line has zero length
    if (px1 == px2 && py1 == py2) return;
    
    // Choose the right roles of x and y, as well as the right starting point
    double x1,y1,x2,y2;
    int switch_xy = 0;
    if (fabs(py2 - py1) > fabs(px2 - px1)) {
        switch_xy = 1;
        if (py1 <= py2) {
            x1 = py1;
            y1 = px1;
            x2 = py2;
            y2 = px2;        
        } else {
            x1 = py2;
            y1 = px2;
            x2 = py1;
            y2 = px1;
        }        
    } else {
        if (px1 <= px2) {
            x1 = px1;
            y1 = py1;
            x2 = px2;
            y2 = py2;        
        } else {
            x1 = px2;
            y1 = py2;
            x2 = px1;
            y2 = py1;
        }
    }
        
    //We assume the right double cone is chosen, i.e. -1 <= m <= 1
    // calculate lines y = m*x + n, x = -m*y + nbar
    const double m = (y2 - y1)/(x2 - x1);
    const double offset = thickness/(2*cos(atan(m)));
    const double n_top = y1 + offset - m*x1;
    const double n_bot = y1 - offset - m*x1;
    const double nbar_left = x1 - offset + m*y1;
    const double nbar_right = x2 + offset + m*y2;

    // At which side of a Pixel the lowest point of a line lies depends on the slope and whether axes are switched
    int switch_sides = 0;
    double absm = m;
    if (m<0) {
        absm *= -1;
        if (switch_xy) {
            switch_sides = 0;
        } else {
            switch_sides = 1;
        }
    } else {
        if (switch_xy) {
            switch_sides = 1;
        } else {
            switch_sides = 0;
        }
    }

    // Corners of the thick line
    // lb means left bottom for example
    double x_lb,y_lb,x_lt,y_lt,x_rb,y_rb,x_rt,y_rt;
    double prefactor = 1/(1+m*m);
    x_lb = prefactor*(nbar_left - m*n_bot);
    y_lb = prefactor*(m*nbar_left + n_bot);
    x_lt = prefactor*(nbar_left - m*n_top);
    y_lt = prefactor*(m*nbar_left + n_top);
    x_rb = prefactor*(nbar_right - m*n_bot);
    y_rb = prefactor*(m*nbar_right + n_bot);
    x_rt = prefactor*(nbar_right - m*n_top);
    y_rt = prefactor*(m*nbar_right + n_top);    

    
    // Variables for the different cases how a line intersects the Pixel
    double lowest, low, high, highest, left, right;
    double w,linesect;
    // Resulting opacity of the Pixel
    double alpha;
    // Main loop to draw pixels    
	//#pragma omp parallel for
	const double a_from = (int)fmax(0.0, floor(fmin(x_lb, x_lt)));
	const double a_to = (int)fmin( (1-switch_xy)*WIDTH + switch_xy*HEIGHT, ceil(fmax(x_rb, x_rt)));
	for (int a = a_from; a < a_to; ++a) {
	    // a has the role of x coordinate
        double b_from = (int)fmax(0.0, floor( m*(a + switch_sides) + n_bot ));
        double b_to = (int)fmin( (1-switch_xy)*HEIGHT + switch_xy*WIDTH , floor(m*(a + switch_sides) + n_top + absm) + 1);
		for (int b = b_from; b < b_to; ++b) {
		    // b has the role of y coordinate
            
            // Set opacity of Pixel to 1 initially
            alpha = 1;
            
            // Cut away from Pixel according to the intersection with the bottom edge
            left = fmax(x_lb,a);
            right = fmin(x_rb,a+1);
            w = fmax(right - left,0);
            switch_sides ? linesect = m*right + n_bot : linesect = m*left + n_bot;
            lowest = (double)b - absm*w;            
            if (linesect > lowest) {
                low = (double)b;
                if (linesect > low) {
                    high = (double)b + 1.0 - absm*w;
                    if (linesect > high) {
                        highest = (double)b + 1.0;
                        if (linesect > highest) {
                            alpha -= w;
                        } else {
                            alpha -= w - pow(highest - linesect, 2)/(2.*absm);
                        }
                    } else {
                        alpha -= (linesect - low + w*absm/2.)*w;
                    }
                } else {
                    alpha -= pow(linesect - lowest, 2)/(2.*absm);
                }            
            }
            
            // Cut away from Pixel according to the intersection with the top edge
            left = fmax(x_lt,a);
            right = fmin(x_rt,a+1);
            w = fmax(right - left,0);
            switch_sides ? linesect = m*right + n_top : linesect = m*left + n_top;
            highest = (double)b + 1.0;            
            if (linesect < highest) {
                high = (double)b + 1.0 - absm*w;
                if (linesect < high) {
                    low = (double)b;
                    if (linesect < low) {
                        lowest = (double)b - absm*w;            
                        if (linesect < lowest) {
                            alpha -= w;
                        } else {
                            alpha -= w - pow(linesect - lowest, 2)/(2.*absm);
                        }
                    } else {
                        alpha -= (high - linesect + w*absm/2.)*w;
                    }
                } else {
                    alpha -= pow(highest - linesect, 2)/(2.*absm);
                }            
            }
            
            if (a <= (int)floor(x1)) {
                // treat left end
                
    		    // Cut away from Pixel according to the intersection with the left edge
                left = fmax(y_lb,b);
                right = fmin(y_lt,b+1);
                w = fmax(right - left, 0);
                switch_sides ? linesect = -m*left + nbar_left : linesect = -m*right + nbar_left;
                lowest = (double)a - absm*w;            
                if (linesect > lowest) {
                    low = (double)a;
                    if (linesect > low) {
                        high = (double)a + 1.0 - absm*w;
                        if (linesect > high) {
                            highest = (double)a + 1.0;
                            if (linesect > highest) {
                                alpha -= w;
                            } else {
                                alpha -= w - pow(highest - linesect, 2)/(2.*absm);
                            }
                        } else {
                            alpha -= (linesect - low + w*absm/2.)*w;
                        }
                    } else {
                        alpha -= pow(linesect - lowest, 2)/(2.*absm);
                    }
                }
                
                // Cut away from Pixel according to the intersection with the top left corner
                alpha -= fmin(fmax(x_lt - a, 0), 1)*fmin(fmax(b + 1 - y_lt, 0), 1);
                // Cut away from Pixel according to the intersection with the bottom left corner
                alpha -= fmin(fmax(x_lb - a, 0), 1)*fmin(fmax(y_lb - b, 0), 1);
            }
            
            if (a >= (int)floor(x2)) {
                // treat rigth end
    		    
    		    // Cut away from Pixel according to the intersection with the right edge
                left = fmax(y_rb,b);
                right = fmin(y_rt,b+1);
                w = fmax(right - left, 0);
                switch_sides ? linesect = -m*left + nbar_right : linesect = -m*right + nbar_right;
                highest = (double)a + 1.0;            
                if (linesect < highest) {
                    high = (double)a + 1.0 - absm*w;
                    if (linesect < high) {
                        low = (double)a;
                        if (linesect < low) {
                            lowest = (double)a - absm*w;            
                            if (linesect < lowest) {
                                alpha -= w;
                            } else {
                                alpha -= w - pow(linesect - lowest, 2)/(2.*absm);
                            }
                        } else {
                            alpha -= (high - linesect + w*absm/2.)*w;
                        }
                    } else {
                        alpha -= pow(highest - linesect, 2)/(2.*absm);
                    }            
                }
                
                // Cut away from Pixel according to the intersection with the top right corner
                alpha -= fmin(fmax(a + 1 - x_rt, 0), 1)*fmin(fmax(b + 1 - y_rt, 0), 1);
                // Cut away from Pixel according to the intersection with the bottom right corner
                alpha -= fmin(fmax(a + 1 - x_rb, 0), 1)*fmin(fmax(y_rb - b, 0), 1);
            }
                        
            int index;
            switch_xy ? index = (HEIGHT - a) * WIDTH + b : index = (HEIGHT - b) * WIDTH + a;
			image[index] = (uint8_t)round(fmin(255.0, (1 - alpha)*image[index] + alpha*color));
		}
	}
}
