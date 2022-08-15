#include <iostream>
#include "pugixml.cpp"

using namespace std;
using namespace pugi;

int main()
{
    cout << "\nParsing Data From File\n\n";

    xml_document doc;

    if (!doc.load_file("Student.xml")){
        cout<<"File Did not open.\n";
        return 0;
    }

    xml_node skip = doc.child("root").child("Source_Data");
x:
    xml_node sam = skip;
    xml_node fName = sam.child( "Customer" );
    xml_node sName = sam.child( "Product" );
    xml_node tName = sam.child( "Qtr_1" );
    int i = 0;
    for (xml_node_iterator it = skip.begin(); it != skip.end(); ++it)
    {

        for (xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait)
        {
            cout << ait->name() << " = " << ait->value() << "\n";
        }


        if( i == 0){
            cout<< "Product = " <<sName.text().get()<<endl;
            cout<< "Customer = " <<fName.text().get()<<endl;
            cout<< "Qtr_1 = " <<tName.text().get()<<endl;
            i++;
        }

        cout << endl;
    }

    skip = skip.next_sibling();
    goto x;

    return 0;

}
