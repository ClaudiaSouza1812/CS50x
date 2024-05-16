#include "helpers.h"
#include <math.h>


/*int main(void)
{
    int n = 3;
    RGBTRIPLE image[n][n];

    image[0][0].rgbtBlue = 10;
    image[0][0].rgbtGreen = 20;
    image[0][0].rgbtRed = 0;

    image[0][1].rgbtBlue = 40;
    image[0][1].rgbtGreen = 50;
    image[0][1].rgbtRed = 128;

    image[0][2].rgbtBlue = 70;
    image[0][2].rgbtGreen = 80;
    image[0][2].rgbtRed = 255;

    image[1][0].rgbtBlue = 110;
    image[1][0].rgbtGreen = 130;
    image[1][0].rgbtRed = 0;

    image[1][1].rgbtBlue = 120;
    image[1][1].rgbtGreen = 140;
    image[1][1].rgbtRed = 128;

    image[1][2].rgbtBlue = 130;
    image[1][2].rgbtGreen = 150;
    image[1][2].rgbtRed = 255;

    image[2][0].rgbtBlue = 110;
    image[2][0].rgbtGreen = 130;
    image[2][0].rgbtRed = 0;

    image[2][1].rgbtBlue = 120;
    image[2][1].rgbtGreen = 140;
    image[2][1].rgbtRed = 128;

    image[2][2].rgbtBlue = 130;
    image[2][2].rgbtGreen = 150;
    image[2][2].rgbtRed = 255;

    edges(n, n, image);
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
                        total_blue += image[adjrow][adjcol].rgbtBlue;
                        total_green += image[adjrow][adjcol].rgbtGreen;
                        total_red += image[adjrow][adjcol].rgbtRed;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //provisory buffer to store the new picture. Sobel's gx and gy matrix (kernels) to
    //calculate every new red, blue e green channels of every pixel;
    RGBTRIPLE buffer[height][width];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    //a variable to each color for every Sobel's matrix (gx, gy);
    double total_bluex, total_redx, total_greenx, total_bluey, total_redy, total_greeny;
    total_bluex = total_redx = total_greenx = total_bluey = total_redy = total_greeny = 0;
    //select the pixel by rows and columns
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            //having the selected pixel as trigger, adjrow will go through every adjacent row of image,
            //including the pixel row, from left to right and top to bottom. The x variable will
            //go through every value of the Sobel's matrix gx;
            for (int adjrow = row - 1, x = 0; adjrow <= row + 1; adjrow++, x++)
            {
                //having the selected pixel as trigger, adjcol will go through every adjacent column,
                //including the pixel column, from left to right and top to bottom. The y variable will
                //go through every value of the Sobel's matrix gy;
                for (int adjcol = col - 1, y = 0; adjcol <= col + 1; adjcol++, y++)
                {
                    //condition that will guarantee only the addition of valid rgbt data per pixel,
                    //by taking the value only within the valid range of height and width;
                    if (adjrow >= 0 && adjrow < height && adjcol >= 0 && adjcol < width)
                    {
                        total_bluex += image[adjrow][adjcol].rgbtBlue * gx[x][y];
                        total_greenx += image[adjrow][adjcol].rgbtGreen * gx[x][y];
                        total_redx += image[adjrow][adjcol].rgbtRed * gx[x][y];

                        total_bluey += image[adjrow][adjcol].rgbtBlue * gy[x][y];
                        total_greeny += image[adjrow][adjcol].rgbtGreen * gy[x][y];
                        total_redy += image[adjrow][adjcol].rgbtRed * gy[x][y];
                    }
                }
            }

            //calculus of every color total value, by rounding the result of the square of
            //color x and color y;
            int tblue = round(sqrt(total_bluex * total_bluex + total_bluey * total_bluey));
            int tgreen = round(sqrt(total_greenx * total_greenx + total_greeny * total_greeny));
            int tred = round(sqrt(total_redx * total_redx + total_redy * total_redy));

            //addition of changed pixel to the buffer, by taking the lower value between the
            //total color and the cap value;
            buffer[row][col].rgbtBlue = fmin(255, tblue);
            buffer[row][col].rgbtGreen = fmin(255, tgreen);
            buffer[row][col].rgbtRed = fmin(255, tred);
            //set the variables values to 0
            tblue = tgreen = tred = total_bluex = total_greenx = total_redx = total_bluey = total_greeny = total_redy = 0;
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


