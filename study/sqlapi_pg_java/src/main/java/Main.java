import java.sql.*;

/**
 * Created by eduardo on 1/1/17.
 */
public class Main {
    public static void main(String[] args) {
        Connection conn = null;
        Statement stm = null;
        ResultSet rs = null;

        try {
            Class.forName("org.postgresql.Driver");
            conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/divina_decor_d",
                    "divina_decor_d", "divina_decor_d");

            stm = conn.createStatement();
            rs = stm.executeQuery("select * from users order by id");

            while (rs.next()) {
                System.out.println(
                    "id[" + rs.getInt(1) + "] email[" + rs.getString(2) + "]"
                );
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } finally {
            close(rs);
            close(stm);
            close(conn);
        }
    }

    private static void close(ResultSet rs) {
        if (rs != null) {
            try {
                rs.close();
            } catch (SQLException e) {
                //Ignore
            }
        }
    }

    private static void close(Statement stm) {
        if (stm != null) {
            try {
                stm.close();
            } catch (SQLException e) {
                //Ignore
            }
        }
    }

    private static void close(Connection conn) {
        if (conn != null) {
            try {
                conn.close();
            } catch (SQLException e) {
                //Ignore
            }
        }
    }
}
