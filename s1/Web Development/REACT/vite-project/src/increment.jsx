import React, { useState } from 'react';

function StepCounter() {
  // State for the main counter value
  const [count, setCount] = useState(0);

  // State for the configurable step amount (from user input)
  const [step, setStep] = useState(0);

  // Handler to update the step amount
  const handleStepChange = (e) => {
    // Convert input to number and default to 1 if empty or invalid
    const newStep = parseInt(e.target.value, 10) || 1;
    setStep(Math.max(1, newStep)); // prevent step < 1
  };

  // Function for incrementing by the user-defined step
  const incrementByStep = () => {
    setCount(prevCount => prevCount + step);
  };

  // Function for decrementing by the user-defined step
  const decrementByStep = () => {
    setCount(prevCount => prevCount - step);
  };

  return (
    <div style={{ textAlign: 'center', marginTop: '50px' }}>
      <h2>Custom Step Counter</h2>

      {/* User input for step value */}
      <div style={{ marginBottom: '20px' }}>
        <label htmlFor="step-input">Enter Step Value: </label>
        <input
          id="step-input"
          type="number"
          value={step}
          onChange={handleStepChange}
          min="1"
          style={{ width: '60px', marginLeft: '10px' }}
        />
      </div>

      {/* Display current count */}
      <h3>Current Count: {count}</h3>

      {/* Control buttons */}
      <div style={{ display: 'flex', justifyContent: 'center', gap: '10px', marginTop: '20px' }}>
        <button onClick={decrementByStep}>- {step}</button>
        <button onClick={incrementByStep}>+ {step}</button>
      </div>
    </div>
  );
}

export default StepCounter;
