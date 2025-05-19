let arrayTeams = [];
let goalsforTeams = [ null, [], [], [] ];
let entryTeam;
let results;
let codePair1 = []
let codePair2 = []
let max = 0;

    while (1){
        entryTeam = prompt("Enter Team and Their Code");
        console.log(entryTeam);
        console.log(entryTeam);
        if(entryTeam === "@"){
           break;
        }
        else {
            entryTeam = entryTeam.split(":");
            arrayTeams[parseInt(entryTeam[1])] = entryTeam[0];
            console.log(arrayTeams);
        }
    }

    while (1){
        results = prompt("Enter Results for the Teams");
        console.log(results);
        if (results !== "@"){
            results = results.split(";");
            codePair1 = results[0];
            console.log(codePair1);
            codePair2 = results[1];
            console.log(codePair2);
            for(let j = 0; j < codePair2.length; j++){
                if (!isNaN(parseInt(codePair2[j]))){
                    max += parseInt(codePair2[j]);
                }
            }

            for(let i = 0; i < codePair1.length; i++){
                if(parseInt(codePair1[i]) === 1){
                    goalsforTeams[1].unshift(parseInt(codePair2[i]));
                }
                if(parseInt(codePair1[i]) === 2){
                    goalsforTeams[2].unshift(parseInt(codePair2[i]));
                }
                if(parseInt(codePair1[i]) === 3){
                    goalsforTeams[3].unshift(parseInt(codePair2[i]));
                }
                else {

                }
            }
            console.log("max is " + max);
            console.log(results);

        }
        else {
            break;
        }
    }

    for (let j = 1; j < arrayTeams.length; j++){
        document.write( j + " " + arrayTeams[j] + " " + goalsforTeams[j] + '<br>');
    }
    document.write(max);
