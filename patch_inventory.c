#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int custom_limits[6];
    const int offsets[] = {
        0x02980,
        0x02D90,
        0x03B60,
        0x06810,
        0x07510,
        0x076B0,
    };
    FILE *bin_file, *custom_limits_file;

    bin_file = fopen("more_resources/bin/dc1/player-inventory.bin", "r+b");
    if (bin_file == NULL)
    {
        printf("Couldn't open file \"more_resources/bin/dc1/player-inventory.bin\".");
        getchar();
        return 1;
    }

    custom_limits_file = fopen("custom_limits.txt", "r");
    if (custom_limits_file == NULL)
    {
        printf("Couldn't open file custom_limits.txt.\n");
        getchar();
        return 1;
    }
    struct stat buffer;
    if (stat(".\\ndarc.exe", &buffer) != 0)
    {
        printf("ndarc.exe wasn't found in this folder.\n");
        getchar();
        return 1;
    }
    char line_buffer[32];
    for (int i = 0; i < 6; ++i)
    {
        if (fscanf(custom_limits_file, "%[^=]=%d\n", line_buffer, custom_limits + i) != 2)
        {
            printf("Error reading line %i the custom_limits.txt file.\n", i);
            getchar();
            return 1;
        }
        fseek(bin_file, offsets[i], SEEK_SET);
        custom_limits[i] *= 4;
        fwrite(custom_limits + i, sizeof(int), 1, bin_file);
        custom_limits[i] /= 4;
        printf("Updated limit for %s from 3 to %d\n", line_buffer, custom_limits[i]);
    }

    fclose(bin_file);
    fclose(custom_limits_file);

    char output_name[64];
    char command[128];
    sprintf_s(output_name, 64, "%d_%d_%d_%d_%d_%d_inventory_limits.psarc",
              custom_limits[0],
              custom_limits[1],
              custom_limits[2],
              custom_limits[3],
              custom_limits[4],
              custom_limits[5]);
    printf("Creating the new archive .\\%s...\n", output_name);
    sprintf_s(command, 128, ".\\ndarc.exe -c .\\more_resources -o .\\%s > NUL", output_name);
    system(command);

    printf("New archive created successfully. You can now copy it into your mods folder. Press any button to quit.\n");
    getchar();

    return 0;
}