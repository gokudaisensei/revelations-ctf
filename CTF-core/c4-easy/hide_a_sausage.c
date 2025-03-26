#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Noise strings to distract reverse engineers.
    char noise1[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    char noise2[] = "Nulla consequat massa quis enim.";

    // The hidden flag embedded in the binary.
    // The keyword SAUSAGE is deliberately included so that the 'strings' command can filter it.
    char hidden_flag[] = "FLAG{SAUSAGE_STRINGS_REVEALED}";

    // More noise text.
    char noise3[] = "Suspendisse potenti. In faucibus massa arcu, vitae cursus mi hendrerit nec.";

    // The program does nothing else.
    return 0;
}
