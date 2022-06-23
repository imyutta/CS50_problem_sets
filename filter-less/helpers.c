#include "helpers.h"
#include <math.h>
#include <stdio.h>
void sepia_change(RGBTRIPLE sepia);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE sepia;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepia.rgbtRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            sepia.rgbtGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            sepia.rgbtBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);

            sepia_change(sepia);
            image[i][j] = sepia;


        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE pixelHolder;
    int last_j;
    int lastElement = width - 1;

    if (width % 2 != 0)
    {
       last_j = (width - 1) / 2 - 1;
    }
    else
    {
       last_j = (width - 1) / 2;
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= last_j; j++)
        {
            pixelHolder = image[i][j];
            image[i][j] = image[i][lastElement - j];
            image[i][lastElement - j] = pixelHolder;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // int blurRed, blurGreen, blurBlue;
    // for (int i = 0; i < height; i++)
    // {
    //     for (int j = 0; j < width; j++)
    //     {
    //         blurRed = image
    //     }
    // }
    return;
}

void sepia_change(RGBTRIPLE sepia)
{
    if (sepia.rgbtRed > 255)
    {
        sepia.rgbtRed = 255;
    }

    if (sepia.rgbtBlue > 255)
    {
        sepia.rgbtBlue = 255;
    }

    if (sepia.rgbtGreen > 255)
    {
        sepia.rgbtGreen = 255;
    }
}