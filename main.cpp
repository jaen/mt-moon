#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream plot_file;

    plot_file.open("plot.txt", ifstream::in);

    cout << "Hello Kanto!" << endl;

    while(plot_file.good()) {
        string line;

        getline(plot_file, line);

        cout << line << endl;
    }

    plot_file.close();

    return 0;
}
