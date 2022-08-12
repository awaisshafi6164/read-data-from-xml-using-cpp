#include <iostream>
#include "pugixml.cpp"

using namespace std;
using namespace pugi;

int main()
{
    cout << "\nParsing Data (sample.xml).....\n\n";

    xml_document doc;

    // load the XML file
    if (!doc.load_file("sample.xml")){
        cout<<"File Didnot open.\n";
        return 0;
    }

    xml_node tools = doc.child("EmployeesData").child("Employees");

    for (xml_node_iterator it = tools.begin(); it != tools.end(); ++it)
    {
        cout << "Employees:\n";

        for (xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait)
        {
            cout << ait->name() << " = " << ait->value() << "\n";
        }

        cout << endl;
    }

    cout << endl;

    return 0;

}
