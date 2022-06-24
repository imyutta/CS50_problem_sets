#include "helpers.h"
#include <math.h>

//int rgb_number(int i, int j, BYTE copy[i - 1][j - 1]);

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
    RGBTRIPLE copy[height][width];
    int blurRed;
    int blurGreen;
    int blurBlue;
    float counter;
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
            //pixel_blur(i, j, RGBTRIPLE image[height][width], RGBTRIPLE copy[height][width]);
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
    RGBTRIPLE copy[height][width];
    RGBTRIPLE pixel[9];
    int g_X_RED, g_Y_RED, g_SUM_RED;
    int g_X_BLUE, g_Y_BLUE, g_SUM_BLUE;
    int g_X_GREEN, g_Y_GREEN, g_SUM_GREEN;

    RGBTRIPLE zeroPixel;

    zeroPixel.rgbtRed = 0;
    zeroPixel.rgbtBlue = 0;
    zeroPixel.rgbtGreen = 0;

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

            for (int k = 0; k < 9; k++)
            {
                pixel[k] = zeroPixel;
            }

            if (is_fits((i - 1), (j - 1)))
            {
            pixel[0].rgbtRed = copy[i - 1][j - 1].rgbtRed;
            pixel[0].rgbtBlue = copy[i - 1][j - 1].rgbtBlue;
            pixel[0].rgbtGreen = copy[i - 1][j - 1].rgbtGreen;
            }
            if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) < height && (j + 1) < width)
            {
            pixel[1].rgbtRed = copy[i - 1][j].rgbtRed;
            pixel[1].rgbtBlue = copy[i - 1][j].rgbtBlue;
            pixel[1].rgbtGreen = copy[i - 1][j].rgbtGreen;
            }
            if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) < height && (j + 1) < width)
            {
            pixel[2].rgbtRed = copy[i - 1][j + 1].rgbtRed;
            pixel[2].rgbtBlue = copy[i - 1][j + 1].rgbtBlue;
            pixel[2].rgbtGreen = copy[i - 1][j + 1].rgbtGreen;
            }


            if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) < height && (j + 1) < width)
            {
            pixel[3].rgbtRed = copy[i][j - 1].rgbtRed;
            pixel[3].rgbtBlue = copy[i][j - 1].rgbtBlue;
            pixel[3].rgbtGreen = copy[i][j - 1].rgbtGreen;
            }
            if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) < height && (j + 1) < width)
            {
            pixel[5].rgbtRed = copy[i][j + 1].rgbtRed;
            pixel[5].rgbtBlue = copy[i][j + 1].rgbtBlue;
            pixel[5].rgbtGreen = copy[i][j + 1].rgbtGreen;
            }


            if (isInside(i-1, j-1, width, heigh) == true)


            if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) < height && (j + 1) < width)
            {
            pixel[6].rgbtRed = copy[i + 1][j - 1].rgbtRed;
            pixel[6].rgbtBlue = copy[i + 1][j - 1].rgbtBlue;
            pixel[6].rgbtGreen = copy[i + 1][j - 1].rgbtGreen;
            }
            if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) < height && (j + 1) < width)
            {
            pixel[7].rgbtRed = copy[i + 1][j].rgbtRed;
            pixel[7].rgbtBlue = copy[i + 1][j].rgbtBlue;
            pixel[7].rgbtGreen = copy[i + 1][j].rgbtGreen;
            }
            if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) < height && (j + 1) < width)
            {
            pixel[8].rgbtRed = copy[i + 1][j + 1].rgbtRed;
            pixel[8].rgbtBlue = copy[i + 1][j + 1].rgbtBlue;
            pixel[8].rgbtGreen = copy[i + 1][j + 1].rgbtGreen;
            }


            g_X_RED = pixel[0].rgbtRed * (-1) + pixel[2].rgbtRed * 1 + pixel[3].rgbtRed * (-2) + pixel[5].rgbtRed * 2 + pixel[6].rgbtRed * (-1) + pixel[8].rgbtRed * 1;
            g_Y_RED = pixel[0].rgbtRed * (-1) + pixel[1].rgbtRed * (-2) + pixel[2].rgbtRed * (-1) + pixel[6].rgbtRed * 1 + pixel[7].rgbtRed * (2) + pixel[8].rgbtRed * 1;
            g_SUM_RED = sqrt(pow(g_X_RED, 2) + pow(g_Y_RED, 2));

            g_X_BLUE = pixel[0].rgbtBlue * (-1) + pixel[2].rgbtBlue * 1 + pixel[3].rgbtBlue * (-2) + pixel[5].rgbtBlue * 2 + pixel[6].rgbtBlue * (-1) + pixel[8].rgbtBlue * 1;
            g_Y_BLUE = pixel[0].rgbtBlue * (-1) + pixel[1].rgbtBlue * (-2) + pixel[2].rgbtBlue * (-1) + pixel[6].rgbtBlue * 1 + pixel[7].rgbtBlue * (2) + pixel[8].rgbtBlue * 1;
            g_SUM_BLUE = sqrt(pow(g_X_BLUE, 2) + pow(g_Y_BLUE, 2));

            g_X_GREEN = pixel[0].rgbtGreen * (-1) + pixel[2].rgbtGreen * 1 + pixel[3].rgbtGreen * (-2) + pixel[5].rgbtGreen * 2 + pixel[6].rgbtGreen * (-1) + pixel[8].rgbtGreen * 1;
            g_Y_GREEN = pixel[0].rgbtGreen * (-1) + pixel[1].rgbtGreen * (-2) + pixel[2].rgbtGreen * (-1) + pixel[6].rgbtGreen * 1 + pixel[7].rgbtGreen * (2) + pixel[8].rgbtGreen * 1;
            g_SUM_GREEN = sqrt(pow(g_X_GREEN, 2) + pow(g_Y_GREEN, 2));



            image[i][j].rgbtRed = round(g_SUM_RED);
            image[i][j].rgbtBlue = round(g_SUM_BLUE);
            image[i][j].rgbtGreen = round(g_SUM_GREEN);

        }
    }
    return;
}

//int is_fits(int x, int y, copy[i - 1][j - 1].rgbtRed)
{
    if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) < height && (j + 1) < width)
}

