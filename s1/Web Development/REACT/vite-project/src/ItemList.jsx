import React from 'react';
import Item from './Item.jsx';

function ItemList() {
  const items = ['Apple', 'Banana', 'Cherry', 'Date', 'Grapes'];

  return (
    <div>
      <h2>Fruit List</h2>
      <ul>
        {items.map((item, index) => (
          <Item key={index} name={item} />
        ))}
      </ul>
    </div>
  );
}

export default ItemList;
