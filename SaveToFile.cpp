#include "SaveToFile.h"

SaveToFile::SaveToFile()
{
}

SaveToFile::~SaveToFile()
{
}

inline void SaveToFile::ignoreNewLine()
{
}

void SaveToFile::saveRecords(vector<Device> allDevices)
{
	//open file for writing

    try {
        cout << "\nWriting contents to file...";
        //open file for writing
        ofstream fw("Devices.txt", std::ofstream::out);
        //check if file was opened for writing
        if (fw.is_open())
        {
            //store array contents to text file
            for (int i = 0; i < allDevices.size(); i++) {
                fw << allDevices[1].power << "\n";
            }
            fw.close();
        }
        else cout << "Problem with opening file";
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }
    cout << "\nDone!";

}
