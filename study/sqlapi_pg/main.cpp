#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

int main(int argc, char *argv[])
{
    try {
        connection conn("dbname=divina_decor_d user=divina_decor_d password=divina_decor_d \
                         hostaddr=127.0.0.1 port=5432");
        if (conn.is_open()) {
            cout << "Opened database successfully: " << conn.dbname() << endl;
        } else {
            cout << "Can not open database" << endl;
            return EXIT_FAILURE;
        }

        string sql = "select * from users order by id";
        cout << sql << endl;

        nontransaction n(conn);
        result r(n.exec(sql));

        for (result::const_iterator it = r.begin(); it != r.end(); ++it) {
           cout << "id[" << it[0].as<int>() << "] email[" << it[1].as<string>() << "]" << endl;
        }

        conn.disconnect();
    } catch (const std::exception &e) {
        cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
