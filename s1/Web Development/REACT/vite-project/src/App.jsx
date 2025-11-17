import { useState } from 'react';
import reactLogo from './assets/react.svg';
import viteLogo from '/vite.svg';
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import './App.css';
{/* 
import Random from './random.jsx';
import Student from './student.jsx';

import UserInput from './StudentDetails.jsx';
import Counter  from './counter';
import ItemList from './ItemList.jsx';
import StepCounter from './increment';
import Button from './Button';
*/}

import Navbar from "./Components/Navbar.jsx";
import Home from "./Pages/Home.jsx";
import About from "./Pages/About.jsx";
import Contact from "./Pages/Contact.jsx";

function App() {
  {/*const [count, setCount] = useState(0); */}

  return (
     <Router>
      <Navbar />
      <div style={{ padding: "20px" }}>
        <Routes>
          <Route path="/" element={<Home />} />
          <Route path="/about" element={<About />} />
          <Route path="/contact" element={<Contact />} />
        </Routes>
        
        
      {/*
      <h1>Welcome to My React App</h1>
      <Random />
      <Student />
      <Counter/>
      <ItemList/>
      <StepCounter/>
       <UserInput/>
       <Button/>
      */}

    </div>
    </Router>
  );
}

export default App;
