import React  from 'react';

function StudentList() {
  // Define an array of student objects
  const students = [
    { id: 1, name: 'Alice Johnson' },
    { id: 2, name: 'Bob Smith' },
    { id: 3, name: 'Charlie Brown' },
    { id: 4, name: 'Diana Prince' },
  ];

  return (
    <div>
      <h2>Student List</h2>
      <ul>
        {students.map(student => (
          <li key={student.id}>
            {student.id}. {student.name}
          </li>
        ))}
      </ul>
    </div>
  );
}

export default StudentList;
