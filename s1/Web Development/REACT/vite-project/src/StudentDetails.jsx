import react , { useState} from 'react' ;

function UserInput(){
    const [inputText, setInputText] = useState('');

    const handleChange = (event) => {
        setInputText(event.target.value);
    };

    return(
        <div>
            <label htmlFor="user-input">Enter Text:</label>
            <input
               id="user-input"
               type="text"
               value={inputText}
               onChange={handleChange}
               placeholder="Type something here..."
            />
          <p>Current Input Value: **{inputText}**</p>
        </div>
    );
}    

export default UserInput;