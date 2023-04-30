
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include "cpu.h"

using namespace std;


class Gameboy{

    public:
        void * load_rom(char* rom_path_str) {
            unsigned int file_size = 0;
            ifstream infile;
            filesystem::path rom_path{rom_path_str};
            file_size = filesystem::file_size(rom_path);
            cout << "Allocating space for rom of size: " << file_size << endl;
            rom_ptr = (char *) malloc(file_size);

            // read the text into the string
            infile.read(rom_ptr,    file_size);
            infile.close();
        }

        int32_t run_rom() {
            ip_ptr = rom_ptr;
            cpu.set_pc(0x0);
            cpu.run();

        }

    private:
        char * rom_ptr;
        char * ip_ptr;
        GBCPU cpu;





};



int main() {

    cout << "Launching emulator!" << endl;
    Gameboy gb;
    gb.load_rom("");

    return 0;
}


