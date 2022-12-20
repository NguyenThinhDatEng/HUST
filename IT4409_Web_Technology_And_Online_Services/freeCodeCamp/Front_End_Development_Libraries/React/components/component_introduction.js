// a Stateless Functional Component
const MyComponent = function () {
  return <div className="customClass">Hello</div>;
};
// Using arrow function
const Camper = (props) => <p>{props.name}</p>;

const CurrentDate = (props) => {
  return (
    <div>
      {/* Change code below this line */}
      <p>The current date is: {props.date}</p>
      <p>The weather may be: {props.weather.join(", ")}</p>
      <strong>Year: {this.props.year}</strong>
      {/* Change code above this line */}
    </div>
  );
};

CurrentDate.defaultProps = {
  month: 10,
  year: 2022,
};

// https://reactjs.org/docs/typechecking-with-proptypes.html
CurrentDate.propTypes = {
  month: PropTypes.number.isRequired,
};

class Calendar extends React.Component {
  constructor(props) {
    super(props);
  }
  render() {
    return (
      <div>
        <h3>What date is it?</h3>
        {/* Change code below this line */}
        <CurrentDate
          date={Date()}
          weather={["Rain", "Sunny", "Windy"]}
          month={12}
        />
        {/* Change code above this line */}
      </div>
    );
  }
}
//   constructor(props) {
//     super(props);
//   }
//   render() {
//     return (
//       <div>
//         <Camper name="NVT" />
//       </div>
//     );
//   }
// }
// // Change code below this line
// class Camper extends React.Component {
//   constructor(props) {
//     super(props);
//   }
//   render() {
//     return <p>{this.prop.name}</p>;
//   }
// }

// Camper.defaultProps = { name: "CamperBot" };
// Camper.propTypes = { name: PropTypes.string.isRequired };
