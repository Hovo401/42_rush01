/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogkarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:06:29 by ogkarape          #+#    #+#             */
/*   Updated: 2023/11/25 18:23:58 by ogkarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void ft_print_char(char* c)
{
    write(1, c, 1);
}

int init(char *arr, char *argv1)
{
    int call;
    int i;

    call = 0;
    i = 0;
    while (argv1[0] != '\0')
    {
        if (48 <= argv1[0] && argv1[0] <= 57)
        {
            arr[call] = argv1[0];
            ++call;
        }
        ++i;
        ++argv1;
    }
    return (call);
}

void place_boxes(char matrix[4][4], char *arr) {
    int row, col;
    int index = 0;

    for (row = 0; row < 4; ++row) {
        for (col = 0; col < 4; ++col) {
            matrix[row][col] = arr[index++];
        }
    }
}

void print_matrix(char matrix[4][4]) {
    int row, col;

    for (row = 0; row < 4; ++row) {
        for (col = 0; col < 4; ++col) {
            ft_print_char(&matrix[row][col]);
            if (col < 3) {
                ft_print_char(" ");
            }
        }
        ft_print_char("\n");
    }
}


int main(int argc, char **argv)
{
    char *arr = (char *)malloc(16);
    char matrix[4][4];
    

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix[i][j] = '0';
        }
    }

    if (argc != 2) {
        write(-1, "Error\n", 6);
        //return 1;
    }

    init(arr, argv[1]);


    

    // Place boxes on the grid
    place_boxes(matrix, arr);

    // Print the solution
    print_matrix(matrix);

    // Free allocated memory
    free(arr);

    return 0;
}
