#include "helpers.h"
#include <math.h>

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
    RGBTRIPLE g_X, g_Y, g_SUM;

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
            pixel[1].rgbtRed = copy[i - 1][j - 1].rgbtRed;
            pixel[1].rgbtBlue = copy[i - 1][j - 1].rgbtBlue;
            pixel[1].rgbtGreen = copy[i - 1][j - 1].rgbtGreen;

            pixel[2].rgbtRed = copy[i - 1][j].rgbtRed;
            pixel[2].rgbtBlue = copy[i - 1][j].rgbtBlue;
            pixel[2].rgbtGreen = copy[i - 1][j].rgbtGreen;

            pixel[3].rgbtRed = copy[i - 1][j + 1].rgbtRed;
            pixel[3].rgbtBlue = copy[i - 1][j + 1].rgbtBlue;
            pixel[3].rgbtGreen = copy[i - 1][j + 1].rgbtGreen;


            pixel[4].rgbtRed = copy[i][j - 1].rgbtRed;
            pixel[4].rgbtBlue = copy[i][j - 1].rgbtBlue;
            pixel[4].rgbtGreen = copy[i][j - 1].rgbtGreen;

            pixel[6].rgbtRed = copy[i][j + 1].rgbtRed;
            pixel[6].rgbtBlue = copy[i][j + 1].rgbtBlue;
            pixel[6].rgbtGreen = copy[i][j + 1].rgbtGreen;


            pixel[7].rgbtRed = copy[i + 1][j - 1].rgbtRed;
            pixel[7].rgbtBlue = copy[i + 1][j - 1].rgbtBlue;
            pixel[7].rgbtGreen = copy[i + 1][j - 1].rgbtGreen;

            pixel[8].rgbtRed = copy[i + 1][j].rgbtRed;
            pixel[8].rgbtBlue = copy[i + 1][j].rgbtBlue;
            pixel[8].rgbtGreen = copy[i + 1][j].rgbtGreen;

            pixel[9].rgbtRed = copy[i + 1][j + 1].rgbtRed;
            pixel[9].rgbtBlue = copy[i + 1][j + 1].rgbtBlue;
            pixel[9].rgbtGreen = copy[i + 1][j + 1].rgbtGreen;


            g_X = pixel[1] * (-1) + pixel[3] * 1 + pixel[4] * (-2) + pixel[6] * 2 + pixel[7] * (-1) + pixel[9] * 1;
            g_Y = pixel[1] * (-1) + pixel[2] * (-2) + pixel[3] * (-1) + pixel[7] * 1 + pixel[8] * (2) + pixel[9] * 1;
            g_SUM = sqrt(pow(g_X, 2) + pow(g_Y, 2));



            image[i][j].rgbtRed = round(blurRed / counter);
            image[i][j].rgbtGreen = round(blurGreen / counter);
            image[i][j].rgbtBlue = round(blurBlue / counter);







        }
    }
    return;
}
