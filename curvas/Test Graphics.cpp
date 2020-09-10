#include "graphics.h"
#include<conio.h>
#include<math.h>

void mapeamento(int xtmax, int xtmin, int ytmax, int ytmin, int xumax, int xumin, int yumax, int yumin, float xu, float yu );

float xt, yt;

void mapeamento(int xtmax, int xtmin, int ytmax, int ytmin, int xumax, int xumin, int yumax, int yumin, float xu, float yu ) {
	
	xt = ((xtmax - xtmin) * (xu - xumin))/(xumax - xumin) + xtmin;
    yt = ((ytmin - ytmax) * (yu - yumin))/(yumax - yumin) + ytmax;

}

void fazCurva(int color, float t, int density) {
	float px, py;
	int maxx = getmaxx();
    int maxy = getmaxy();
	while(t<=1){
   	px = pow((1-t),3) * 1 + 3 * t * pow((1-t),2) * 2 + 3 * pow(t,2) * (1-t) * 4 + pow(t,3) * density;
    py = pow((1-t),3) * 1 + 3 * t * pow((1-t),2) * 3 + 3 * pow(t,2) * (1-t) * 3 + pow(t,3) * 1;
    
     mapeamento(maxx, 0, maxy, 0, 6, 0, 6, 0, px, py );
	
	putpixel(xt, yt, color);
	t = t + 0.1;
   	
   }
 
 	getch();
 	clearviewport();
}

int main()
{
   int maxx, maxy, poly[10], i, errorcode;
   int gd = DETECT, gm;
   float px, py;
  
   initgraph(&gd, &gm, "");
   errorcode=graphresult();
   if(errorcode)
       exit(1);

   maxx = getmaxx();
   maxy = getmaxy();
   
   setviewport(0,0,maxx,maxy,1);
   fazCurva(WHITE, 0, 3);
   fazCurva(BLUE, 0, 3);
   fazCurva(GREEN, 0, 5);
   fazCurva(YELLOW, 0, 5);
 
   closegraph();
   return 0;
}
