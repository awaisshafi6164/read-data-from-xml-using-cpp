#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

string getFile( string filename );
vector<string> getData( const string &text, string tag );
void stripTags( string &text );

int main()
{
   //string filename = "input.xml";
   //string tag = "name";
   //string tag = "object";

   string filename = "Student.xml";
   string tag = "Source_Data";
   //string tag = "Qtr_2";

   //string filename = "employee.xml";
   //string tag = "row";
   //string tag = "password";

   bool stripOtherTags = true;

   string text = getFile( filename );

   vector<string> all = getData( text, tag );

   for ( string &s : all )
   {
      if ( stripOtherTags )
          stripTags( s );

      cout << s << '\n';
   }

}

string getFile( string filename )
{
   string text;
   char c;

   ifstream in( filename );
   if ( !in )
    {
        cout << "File not found\n";
        exit( 0 );
    }

   while ( in.get( c ) )
        text += c;

   in.close();

   return text;
}

vector<string> getData( const string &text, string tag )
{
   vector<string> collection;
   int pos = 0, start;

   while ( true )
   {
      start = text.find( "<" + tag, pos );

      if ( start == string::npos )
            return collection;

      start = text.find( ">" , start );
      start++;

      pos = text.find( "</" + tag, start );

      if ( pos == string::npos )
            return collection;

      collection.push_back( text.substr( start, pos - start ) );
   }

}

void stripTags( string &text )
{
   int start = 0, pos;

   while ( start < text.size() )
   {
      start = text.find( "<", start );

      if ( start == string::npos )
        break;
      pos   = text.find( ">", start );

      if ( pos   == string::npos )
        break;

      text.erase( start, pos - start + 1 );
   }
}
