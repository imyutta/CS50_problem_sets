#include "helpers.h"
#include <math.h>
#include <stdio.h>
int boundary_check(int a);
//void pixel_blur(int i, int j, RGBTRIPLE image, RGBTRIPLE copy);


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
            sepia.rgbtRed = boundary_check(round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));
            sepia.rgbtGreen = boundary_check(round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            sepia.rgbtBlue = boundary_check(round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));

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
    RGBTRIPLE copy[height][width];
    int blurRed;
    int blurGreen;
    int blurBlue;
    int counter;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
            //pixel_blur(i, j, RGBTRIPLE image[height][width], copy);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
                blurRed = 0;
            blurGreen = 0;
            blurBlue = 0;
            counter = 0;
            for (int first_i = i - 1, last i = i + 1; p < i + 2; p++)
            {
                if (p >= 0 && p < height)
                {
                    for (int z = j - 1; z < j + 2; z++)
                    {
                        if (z >= 0 && z < width)
                        {
                            blurRed += copy[p][z].rgbtRed;
                            blurGreen += copy[p][z].rgbtGreen;
                            blurBlue += copy[p][z].rgbtBlue;
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

int boundary_check(int a)
{
    if (a > 255)
    {
        return 255;
    }
    else
    {
        return a;
    }
}

// void pixel_blur(int i, int j, RGBTRIPLE image, RGBTRIPLE copy)
// {
//     int blurRed = 0;
//     int blurGreen = 0;
//     int blurBlue = 0;
//     int counter = 0;
//     for (int p = i - 1; p < i + 2; p++)
//     {
//         if (p >= 0 && p < height)
//         {
//             for (int z = j - 1; z < j + 2; z++)
//             {
//                 if (z >= 0 && z < width)
//                 {
//                     blurRed += copy[p][z].rgbtRed;
//                     blurGreen += copy[p][z].rgbtGreen;
//                     blurBlue += copy[p][z].rgbtBlue;
//                     counter++;

//                 }
//             }
//         }
//     }
//     image[i][j].rgbtRed = round(blurRed / counter);
//     image[i][j].rgbtGreen = round(blurGreen / counter);
//     image[i][j].rgbtBlue = round(blurBlue / counter);
// }
