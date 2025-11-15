
#include <stdio.h>
int main() {
    int rect_rows = 10, rect_cols = 14;
    int sq_size = 4;

    int n = 7;
    int rect_width = 2 * n + 1; // Make rectangle width match triangle base
    
    // Triangle part
    for (int i = 0; i < n; i++) {
        // Print leading spaces to center triangle
        for (int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        // Print left slash
        printf("/");
        for (int k = 0; k < 2*i - 1; k++) {
                printf(" ");
        }
        // Print right slash
        if (i > 0) {
            printf("\\");
        }
        printf("\n");
    }


    // Position squares just above the middle of rectangle
    int mid_row = rect_rows / 2;
    int sq_start_row = mid_row - sq_size;           // Squares start just above middle
    int sq1_start_col = 1;                           // Left square starts near left edge
    int sq2_start_col = rect_cols - sq_size - 1;    // Right square near right edge
    
    int door_width = 7;
    int door_height = 3;
    int door_start_row = rect_rows - door_height - 1;
    int door_start_col = (rect_cols - door_width) / 2;


    for (int i = 0; i < rect_rows; i++) {
        for (int j = 0; j < rect_cols; j++) {
            int rect_border_row = (i == 0 || i == rect_rows - 1);
            int rect_border_col = (j == 0 || j == rect_cols - 1);

            // for left side square
            int inside_sq1 = (i >= sq_start_row && i < sq_start_row + sq_size &&
                              j >= sq1_start_col && j < sq1_start_col + sq_size);
            int sq1_border_row = (i == sq_start_row || i == sq_start_row + sq_size - 1);
            int sq1_border_col = (j == sq1_start_col || j == sq1_start_col + sq_size - 1);

            // for right side square
            int inside_sq2 = (i >= sq_start_row && i < sq_start_row + sq_size &&
                              j >= sq2_start_col && j < sq2_start_col + sq_size);
            int sq2_border_row = (i == sq_start_row || i == sq_start_row + sq_size - 1);
            int sq2_border_col = (j == sq2_start_col || j == sq2_start_col + sq_size - 1);

            // for the bottom door
            int inside_door = (i >= door_start_row && i < door_start_row + door_height &&
                          j >= door_start_col && j < door_start_col + door_width);
            int door_border_row = (i == door_start_row); // bottom horizontal border of door
            int door_border_col = (j == door_start_col || j == door_start_col + door_width - 1); // vertical borders door

            if (rect_border_row) {
                printf("_");
            } else if (rect_border_col) {
                printf("|");
            } else if (inside_sq1 && (sq1_border_row || sq1_border_col)) {
                if (sq1_border_row)
                    printf("_");
                else
                    printf("|");
            } else if (inside_sq2 && (sq2_border_row || sq2_border_col)) {
                if (sq2_border_row)
                    printf("_");
                else
                    printf("|");
            } 
            else if (inside_door && (door_border_row || door_border_col)) {
            // Print door border
            if (door_border_row)
                printf("_");
            else
                printf("|");
        } else if (inside_door) {
            // Hollow inside door
            printf(" ");
        } else {
            printf(" ");
        }
        }
        printf("\n");
    }

    return 0;
}
