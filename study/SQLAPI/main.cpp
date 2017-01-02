#include <iostream>
#include <SQLAPI.h>

using namespace std;

int main(int argc, char **argv)
{
    SAConnection conn;

    cout << "Hello world!" << endl;

    try {
        //conn.Connect("divina_decor_d", "divina_decor_d", "divina_decor_d", SA_PostgreSQL_Client);

        cout << "Conexao realizada com sucesso" << endl;

        //conn.Disconnect();

        cout << "Desconectado!" << endl;
    } catch (SAException &e) {
        cerr << "Erro ao tentar conexao no banco de dados" << endl;
        //return EXIT_
    }
    return 0;
}
