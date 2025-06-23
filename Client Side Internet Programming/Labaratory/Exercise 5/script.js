
const students = [
    { number: 1 , name: "Alice", surname: "Smith", points: 78 },
    { number: 2 , name: "Bob", surname: "Johnson", points: 45 },
    { number: 3 , name: "Charlie", surname: "Williams", points: 50 },
    { number: 4 , name: "Diana", surname: "Brown", points: 30 },
    { number: 5 , name: "Eve", surname: "Davis", points: 95 },
];
const tableBody = document.querySelector("#studentTable tbody");
students.forEach(student => {
    const row = document.createElement("tr");
    row.innerHTML = `
    <td>${student.number}</td>
    <td>${student.name}</td>
    <td>${student.surname}</td>
    <td>${student.points}</td>
  `;
    tableBody.appendChild(row);
});
const passedButton = document.getElementById("passedButton");
const failedButton = document.getElementById("failedButton");
const clearButton = document.getElementById("clearButton");
const resultText = document.getElementById("resultText");

passedButton.addEventListener("click", () => {
    let passedCount = 0;
    const rows = tableBody.querySelectorAll("tr");
    rows.forEach((row, index) => {
        const points = students[index].points;
        if (points >= 50) {
            row.classList.add("passed");
            row.classList.remove("failed");
            passedCount++;
        } else {
            row.classList.remove("passed");
        }
    });
    resultText.textContent = `Passed: ${passedCount}`;
});

failedButton.addEventListener("click", () => {
    let failedCount = 0;
    const rows = tableBody.querySelectorAll("tr");
    rows.forEach((row, index) => {
        const points = students[index].points;
        if (points < 50) {
            row.classList.add("failed");
            row.classList.remove("passed");
            failedCount++;
        } else {
            row.classList.remove("failed");
        }
    });
    resultText.textContent = `Failed: ${failedCount}`;
});



clearButton.addEventListener("click", () => {
    const rows = tableBody.querySelectorAll("tr");
    rows.forEach(row => {
        row.classList.remove("passed");
        row.classList.remove("failed");
    });
    resultText.textContent = "";
});
