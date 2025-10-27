const con = require('./conn.js');
 
const cr_Tb = `
    CREATE TABLE IF NOT EXISTS t_db.students (
        rollno INT PRIMARY KEY,
        name VARCHAR(15)
    )
`;
 
// Run the query
con.query(cr_Tb, (err) => {
    if (err) throw err;
    console.log('Table students created');
});