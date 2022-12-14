#include <iostream>
#include "pugixml.cpp"

using namespace std;
using namespace pugi;

int main()
{
    cout << "\nParsing Data From File\n\n";

    xml_document doc;

    if (!doc.load_file("sample.xml")){
        cout<<"File Did not open.\n";
        return 0;
    }

    xml_node skip = doc.child("root").child("Source_Data");
x:
    xml_node sam = skip;
    xml_node fName = sam.child( "Employee" );

    for (xml_node_iterator it = skip.begin(); it != skip.end(); ++it)
    {
        for (xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait)
        {
            cout << ait->name() << " = " << ait->value() << "\n";

        }
        cout<< "Text = " <<fName.text().get()<<endl;
        fName = fName.next_sibling( "Employee" );

        cout << endl;
    }

    skip = skip.next_sibling();
    goto x;

    return 0;

}
