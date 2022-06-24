#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <cs50.h>

bool is_fits(int x, int y, int height, int width);
int boundary_check(int a);


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            average = round((pixel.rgbtBlue + pixel.rgbtGreen + pixel.rgbtRed) / 3.0);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE pixelHolder;
    // int last_j;
    int lastElement = width - 1;

    int last_j = floor(width / 2) - 1;

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
    //make a copy of the image
    RGBTRIPLE copy[height][width];

    int blurRed;
    int blurGreen;
    int blurBlue;
    float counter;

   //make a copy of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];

        }
    }

    // take each pixel and, for each color value
    // give it a new value by averaging the color values of neighboring pixels.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            blurRed = 0;
            blurGreen = 0;
            blurBlue = 0;
            counter = 0;
            for (int row = i - 1, last_row = i + 1; row <= last_row; row++)
            {
                if (row >= 0 && row < height)
                {
                    for (int column = j - 1, last_column = j + 1; column <= last_column; column++)
                    {
                        if (column >= 0 && column < width)
                        {
                            blurRed += copy[row][column].rgbtRed;
                            blurGreen += copy[row][column].rgbtGreen;
                            blurBlue += copy[row][column].rgbtBlue;
                            counter++;

                        }
                    }
                }
            }
            //average the color values of neighboring pixels and rewrite the image
            image[i][j].rgbtRed = round(blurRed / counter);
            image[i][j].rgbtGreen = round(blurGreen / counter);
            image[i][j].rgbtBlue = round(blurBlue / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //copy of the sourse image
    RGBTRIPLE copy[height][width];
    //array of pixels surrounding the current pixel
    RGBTRIPLE pixel[9];

    int g_X_RED, g_Y_RED;
    int g_X_BLUE, g_Y_BLUE;
    int g_X_GREEN, g_Y_GREEN;
    float g_SUM_RED, g_SUM_BLUE, g_SUM_GREEN;

    RGBTRIPLE zeroPixel;
    zeroPixel.rgbtRed = 0;
    zeroPixel.rgbtBlue = 0;
    zeroPixel.rgbtGreen = 0;

    //copy of the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //all of the 9 pixels are temporarily equaled to 0
            for (int k = 0; k < 9; k++)
            {
                pixel[k] = zeroPixel;
            }

            //check if the surrounding pixels fit the image boarders
            //if fit, rewrite their values by applying Sobel operator
            if (is_fits((i - 1), (j - 1), height, width))
            {
                pixel[0] = copy[i - 1][j - 1];
            }

            if (is_fits((i - 1), j, height, width))
            {
                pixel[1] = copy[i - 1][j];

            }
            if (is_fits((i - 1), (j + 1), height, width))
            {
                pixel[2] = copy[i - 1][j + 1];
            }


            if (is_fits(i, (j - 1), height, width))
            {
                pixel[3] = copy[i][j - 1];
            }
            //skip the middle pixel
            if (is_fits(i, (j + 1), height, width))
            {
                pixel[5] = copy[i][j + 1];
            }



            if (is_fits((i + 1), (j - 1), height, width))
            {
                pixel[6] = copy[i + 1][j - 1];
            }
            if (is_fits((i + 1), j, height, width))
            {
                pixel[7] = copy[i + 1][j];
            }
            if (is_fits((i + 1), (j + 1), height, width))
            {
                pixel[8] = copy[i + 1][j + 1];
            }

            //find and combine Gx and Gy for red
            g_X_RED = pixel[0].rgbtRed * (-1) + pixel[2].rgbtRed * 1 + pixel[3].rgbtRed * (-2) + pixel[5].rgbtRed * 2 + pixel[6].rgbtRed *
                      (-1) + pixel[8].rgbtRed * 1;
            g_Y_RED = pixel[0].rgbtRed * (-1) + pixel[1].rgbtRed * (-2) + pixel[2].rgbtRed * (-1) + pixel[6].rgbtRed * 1 + pixel[7].rgbtRed *
                      (2) + pixel[8].rgbtRed * 1;
            g_SUM_RED = sqrt(pow(g_X_RED, 2) + pow(g_Y_RED, 2));

            //find and combine Gx and Gy for blue
            g_X_BLUE = pixel[0].rgbtBlue * (-1) + pixel[2].rgbtBlue * 1 + pixel[3].rgbtBlue * (-2) + pixel[5].rgbtBlue * 2 + pixel[6].rgbtBlue *
                      (-1) + pixel[8].rgbtBlue * 1;
            g_Y_BLUE = pixel[0].rgbtBlue * (-1) + pixel[1].rgbtBlue * (-2) + pixel[2].rgbtBlue * (-1) + pixel[6].rgbtBlue * 1 +
                      pixel[7].rgbtBlue * (2) + pixel[8].rgbtBlue * 1;
            g_SUM_BLUE = sqrt(pow(g_X_BLUE, 2) + pow(g_Y_BLUE, 2));

            //find and combine Gx and Gy for green
            g_X_GREEN = pixel[0].rgbtGreen * (-1) + pixel[2].rgbtGreen * 1 + pixel[3].rgbtGreen * (-2) + pixel[5].rgbtGreen * 2 +
                      pixel[6].rgbtGreen * (-1) + pixel[8].rgbtGreen * 1;
            g_Y_GREEN = pixel[0].rgbtGreen * (-1) + pixel[1].rgbtGreen * (-2) + pixel[2].rgbtGreen * (-1) + pixel[6].rgbtGreen * 1 +
                     pixel[7].rgbtGreen * (2) + pixel[8].rgbtGreen * 1;
            g_SUM_GREEN = sqrt(pow(g_X_GREEN, 2) + pow(g_Y_GREEN, 2));


            //rewrite the image pixels
            image[i][j].rgbtRed = boundary_check(round(g_SUM_RED));
            image[i][j].rgbtBlue = boundary_check(round(g_SUM_BLUE));
            image[i][j].rgbtGreen = boundary_check(round(g_SUM_GREEN));

        }
    }
    return;
}

//check if the pixel fits the boarders
bool is_fits(int x, int y, int height, int width)
{
    if (x >= 0 && y >= 0 && x < height && y < width)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//check if the value is under or equal to 255
int boundary_check(int a)
{
    return (a > 255) ? 255 : a;
}
