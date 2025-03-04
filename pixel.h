#ifndef PIXEL_H
#define PIXEL_H

struct _pixel
{
    float r;  // Red component
    float g;  // Green component
    float b;  // Blue component
    int x;    // X-coordinate
    int y;    // Y-coordinate
};
typedef struct _pixel Pixel;

#endif
