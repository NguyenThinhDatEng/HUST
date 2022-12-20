class MyComponent extends React.Component {
  constructor(props) {
    super(props);
    // a Stateful Component
    this.state = {
      firstName: "Thinh",
      age: 21,
      isSingle: true,
      university: "HUST",
    };
    this.handleClick = this.handleClick.bind(this);
    this.reset = this.reset.bind(this);
  }
  // function 01
  handleClick() {
    this.setState((state) => {
      return {
        age: age + 1,
        isSingle: !state.isSingle,
      };
    });
  }
  // func 02
  reset() {
    this.setState({ age: 21 });
  }

  render() {
    // init variables
    const age = this.state.age;
    // return
    return (
      <div>
        <button onClick={this.handleClick}>Click Me</button>
        <button onClick={this.reset}>RESET</button>
        <h2>I'm {this.state.firstName}</h2>
        <h3>I'm {age}</h3>
        {/* Create a Controlled Input */}
        <input value={this.state.input} onChange={this.handleChange} />
        <p>Input: {this.state.input}</p>
        {/* Pass State as Props to Child Components */}
        {/* Child Component */}
        <ParentComponent
          university={this.state.university}
          age={this.state.age}
          // Pass a Callback as Props
          handleClick={this.handleClick}
        />
      </div>
    );
    // Change code above this line
  }
}

const ChildComponent = () => {
  return (
    <div>
      <p>I am the child</p>
    </div>
  );
};

// a Component with Composition
class ParentComponent extends React.Component {
  constructor(props) {
    super(props);
  }
  render() {
    return (
      <div>
        <h1>I am the parent</h1>
        <ChildComponent />
        <h2>University: {this.props.university}</h2>
        <button onClick={this.props.handleClick}>Increase my age</button>
      </div>
    );
  }
}

// Render a Class Component to the DOM
ReactDOM.render(<MyComponent />, document.getElementById("challenge-node"));

// this.setState((state, props) => ({
//   counter: state.counter + props.increment
// }));
