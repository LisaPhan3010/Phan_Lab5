#include <stdio.h>

void display(int td, int fg, int td1, int fg1, int td2, int fg2, int safety) {
    printf("%d TD + %d 2pt, %d TD + %d FG, %d TD + %d FG, %d TD + %d FG, %d Safety\n", 
           td, td * 2, td1, fg1, td2, fg2, td + td1 + td2, fg + fg1 + fg2, safety);
}

int main(void) {
    int score, td, fg, safety;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays:\n");

        for (td = 0; td <= score / 8; td++) {
            for (fg = 0; fg <= (score - td * 8) / 3; fg++) {
                for (int td1 = 0; td1 <= (score - td * 8 - fg * 3) / 8; td1++) {
                    for (int fg1 = 0; fg1 <= (score - td * 8 - fg * 3 - td1 * 8) / 3; fg1++) {
                        for (int td2 = 0; td2 <= (score - td * 8 - fg * 3 - td1 * 8 - fg1 * 3) / 8; td2++) {
                            for (int fg2 = 0; fg2 <= (score - td * 8 - fg * 3 - td1 * 8 - fg1 * 3 - td2 * 8) / 3; fg2++) {
                                safety = (score - td * 8 - fg * 3 - td1 * 8 - fg1 * 3 - td2 * 8 - fg2 * 3) / 2;

                                if (td * 8 + fg * 3 + td1 * 8 + fg1 * 3 + td2 * 8 + fg2 * 3 + safety * 2 == score) {
                                    display(td, fg, td1, fg1, td2, fg2, safety);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
