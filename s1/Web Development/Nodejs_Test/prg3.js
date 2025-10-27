const con = require('./conn.js');
 
// SQL query to insert one record
const sql = "INSERT INTO t_db.students (rollno, name) VALUES (6, 'Ram')";
 
    con.query(sql, (err, result) => {
  if (err) throw err;
  console.log('Record inserted successfully!');
    con.end(); // close the connection
});