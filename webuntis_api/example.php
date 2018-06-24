<?php
    date_default_timezone_set('CET');
    
    $username = $_GET["username"];
    $password = $_GET["password"];

    require "webuntis.php";

    $untis = new Webuntis();
    
    #auth('url', 'schoolname', 'username', 'password');
    $untis->auth('mese.webuntis.com', 'htbla%20linz%20leonding', $username, $password);
    
    $table      = $untis->getTimetable();
    $subjects   = $untis->getSubjects();
    $teachers   = $untis->getTeachers();
    $rooms      = $untis->getRooms();
    
    $currenttime = date('hi');
    $currenttime = intval($currenttime);
    
    $endtime = 0;
    $comparestarttime = 0;
    
    $foundcurrent = 0;
    
    print_r("Current UE: ");
    for($i = 0; $i < sizeof($table['result']); $i++){
        $endtime= intval($table['result'][$i]['endTime']);
        $comparestarttime = intval($table['result'][$i]['startTime']);
        if(($currenttime < $endtime) && ($currenttime > $comparestarttime)){
            print_r(" now: ");
            print_r($currenttime);
            print_r(" end: ");
            print_r($endtime);
            print_r(" begin: ");
            print_r($comparestarttime);
            print_r(" room: ");
            print_r($table['result'][$i]['ro'][0]['id']);
            $foundcurrent = 1;
        }
    }
    
    $untis->logout();
    
?>
