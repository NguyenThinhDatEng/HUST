const JSX = (
  <div className="myDiv">
    {/** Define an HTML Class in JSX */}
    <h1>Hello World</h1>
    {/** Self-Closing JSX Tags */}
    <br />
    <p>Lets render this to the DOM</p>
    <h1>Add a class to this div</h1>
  </div>
);
// Change code below this line
// There is a div with id='challenge-node' available to use
ReactDOM.render(JSX, document.getElementById("challenge-node"));
