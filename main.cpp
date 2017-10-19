// https://ideone.com/mt1MLS fork


    #include <iostream>
    #include <iomanip>
    #include <fstream>

    using namespace std;

    int main(int argc, char *argv[]) {
        if(argc != 2) {
            cout << "usage: " << argv[0] << " <filename>\n";
            return 1;
        }

        unsigned long address = 0;


        cout << hex << setfill('0');
        ifstream file(argv[1], ios::in|ios::binary);
        while( file.good() )
        {
            int nread;
            char buf[16];
            unsigned unbuf[16];

            for( nread = 0; nread < 16 && file.get(buf[nread]); nread++ );  //try static_cast, dynamic_cast and reinterpret_cast
            if( nread == 0 ) break;


             //Show the address
            cout << setw(8) << address;


            // Show the hex codes
            for( int i = 0; i < 16; i++ )
            {
                unbuf[i] = reinterpret_cast<unsigned char&>(buf[i]);
                if( i % 8 == 0 ) cout << "   ";
                else if( i % 2 ==0) cout << " ";
    	        if( i < nread )
                    cout << setw(2) << std::uppercase <<unbuf[i];
                else
                    cout << "  ";
            }

            cout << "  ";
             //Show the ASCII symbols
            for( int i = 0; i < nread; i++)
            {
                if( buf[i] < 32|| buf[i]> 127 ) cout << '.';
                else cout << buf[i];
            }

            cout << "\n";
            address += 16;

        }
    	return 0;
    }
