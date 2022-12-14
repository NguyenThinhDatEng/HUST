class MyComponent extends React.Component {
  constructor(props) {
    super(props);
  }
  render() {
    // Change code below this line
    return (
      <div>
        <h1>Hello React!</h1>
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
        {/* Change code below this line */}
        <ChildComponent />
        {/* Change code above this line */}
      </div>
    );
  }
}
