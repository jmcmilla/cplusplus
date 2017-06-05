#include "../ppm.h"
#include <math.h>
#include <stdlib.h>
#include "../grapher.h"

Grapher::Grapher(double minX, double minY, double maxX, double maxY)
  {
    MinX = minX;
    MinY = minY;
    MaxX = maxX;
    MaxY = maxY;
    AxesDrawn = false;
  }
double fx(double x)
  {
  double y = fabs(x) * cos(x);
  return y;
}

void Grapher::DrawAxes()
  {
  if (!AxesDrawn)
    {
    double xrang = MaxX - MinX;
    double yrang = MaxY - MinY;
    double horizantalpxpu = 1024.0 / xrang;
    double verticalpxpu = 1024.0 / yrang;
    double absminx = fabs(MinX);
    double yaxisloc = absminx * horizantalpxpu;
    double absmaxy = fabs(MaxY);
    double xaxisloc = absmaxy * verticalpxpu;

    Image.Rect(0, 0, 1024, 1024, 0xffccff);
    Image.Line(yaxisloc, 0, yaxisloc, 1024, 0x000000);
    Image.Line(0, xaxisloc, 1024, xaxisloc, 0x000000);

    for( double i = 0; i <= 1024; i += horizantalpxpu)
      {
      Image.Line(i, xaxisloc - 10, i, xaxisloc + 10, 0x000000);
      }
    for( double i = 0; i <= 1024; i += verticalpxpu)
      {
      Image.Line(yaxisloc - 10, i, yaxisloc + 10, i, 0x000000);
      }
      AxesDrawn = true;
    }
  }
void Grapher::Plot(double (*f)(double), int color)
{
  DrawAxes();
  double xrang = MaxX - MinX;
  double yrang = MaxY - MinY;

  int oldj = 0;
  for ( int i = 0; i < 1024; i++)
    {
    double x = xrang / 1024.0 * i - fabs(MinX);
    double y = f(x);
    int j = 1024 -(y + fabs(MinY)) * 1024.0 / yrang;
    Image.Pixel(i, j, color);
    if( i != 0)
      {
      Image.Line(i - 1, oldj, i, j, color);
      }
    oldj = j;
    }
}

PPM & Grapher::GetImage()
  {
    return Image;
  }

int main()
{
  // See pgm.h for what these parameters do.
  //img.Rect(512 - 300, 512 - 300, 600, 600, 128);
  Grapher grapher (-20, -20, 20, 20);
  grapher.Plot(sin, 0xff0000);
  grapher.Plot(fx, 0x66ff33);
  grapher.GetImage().Show();
  return 0;
}
