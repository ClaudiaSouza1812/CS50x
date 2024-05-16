#include "helpers.h"

#include <math.h>

/*int main(void)
{
    int n = 3;
    RGBTRIPLE image[n][n];

    image[0][0].rgbtBlue = 10;
    image[0][0].rgbtGreen = 20;
    image[0][0].rgbtRed = 30;

    image[0][1].rgbtBlue = 40;
    image[0][1].rgbtGreen = 50;
    image[0][1].rgbtRed = 60;

    image[0][2].rgbtBlue = 70;
    image[0][2].rgbtGreen = 80;
    image[0][2].rgbtRed = 90;

    image[1][0].rgbtBlue = 110;
    image[1][0].rgbtGreen = 130;
    image[1][0].rgbtRed = 140;

    image[1][1].rgbtBlue = 120;
    image[1][1].rgbtGreen = 140;
    image[1][1].rgbtRed = 150;

    image[1][2].rgbtBlue = 130;
    image[1][2].rgbtGreen = 150;
    image[1][2].rgbtRed = 160;

    blur(n, n, image);
}*/

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int b = image[i][j].rgbtBlue;
            int g = image[i][j].rgbtGreen;
            int r = image[i][j].rgbtRed;
            int avg = round((b + g + r) / 3.0);

            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int ob = image[i][j].rgbtBlue;
            int og = image[i][j].rgbtGreen;
            int or = image[i][j].rgbtRed;

            int nb = round((.272 * or) + (.534 * og) + (.131 * ob));
            int ng = round((.349 * or) + (.686 * og) + (.168 * ob));
            int nr = round((.393 * or) + (.769 * og) + (.189 * ob));

            image[i][j].rgbtBlue = fmin(255, nb);
            image[i][j].rgbtGreen = fmin(255, ng);
            image[i][j].rgbtRed = fmin(255, nr);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //provisory buffer to preserve the original picture, a double data counter and total color variables
    RGBTRIPLE buffer[height][width];
    double counter, total_blue, total_red, total_green;
    counter = total_blue = total_red = total_green = 0;
    //select the pixel by rows and columns
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            //having the selected pixel as trigger, adjrow will go through every adjacent row,
            //including the pixel row, from left to right and top to botton
            for (int adjrow = row - 1; adjrow <= row + 1; adjrow++)
            {
                //having the selected pixel as trigger, adjcol will go through every adjacent column,
                //including the pixel column, from left to right and top to botton
                for (int adjcol = col - 1; adjcol <= col + 1; adjcol++)
                {
                    //condition that will guarantee only the addition of valid rgbt data per pixel
                    if (adjcol >= 0 && adjcol < width && adjrow >= 0 && adjrow < height)
                    {
                        total_blue = total_blue + image[adjrow][adjcol].rgbtBlue;
                        total_green = total_green + image[adjrow][adjcol].rgbtGreen;
                        total_red = total_red + image[adjrow][adjcol].rgbtRed;
                        counter++;
                    }
                }
            }
            //addition of changed pixel to the buffer, by rounding the result of summed values divided by
            //the number of valid pixels
            buffer[row][col].rgbtBlue = round(total_blue / counter);
            buffer[row][col].rgbtGreen = round(total_green / counter);
            buffer[row][col].rgbtRed = round(total_red / counter);

            //set the variables values to 0
            counter = total_blue = total_green = total_red = 0;
        }
    }
    //pass the buffer values to make a new image
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l] = buffer[k][l];
        }
    }
    return;
}
