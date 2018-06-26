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
    
    $currenttime = date('Hi');
    $currenttime = intval($currenttime);

    $stack = array();
    $line = "";
    
    $i = 0;
    $j = 0;
    
    foreach($table['result'] as $class){
        $roomnumber = $table['result'][$i]['ro'][0]['id'];
        
        foreach($rooms['result'] as $roomname){
            if($roomname['id'] == $roomnumber){
                $roomnumber = $roomname['name'];
                break;
            }
        }
        
        $line = $line . $table['result'][$i]['startTime'];
        if(strlen($line) == 3){
            $line = '0' . $line;
        }
        $checkendtime = $table['result'][$i]['endTime'];
        if(strlen($checkendtime) == 3){
            $line = $line . "0";
        }
        $line = $line . $table['result'][$i]['endTime'];
        $line = $line . $roomnumber;
        array_push($stack, $line);
        $line = "";
        $i++;
    }
    
    function cmp($a, $b)
    {
        return strcmp($a, $b);
    }

    usort($stack, "cmp");
   
    $current = " ";
    $prev = " ";
    $k = 0;
   
    foreach($stack as $checkline){
        $current = substr($checkline, 0, 4);
        if($current == $prev){
            unset($stack[$k]);
        }
        $k++;
        $prev = $current;
    }
    
    $beginning = 0;
    $two = 0;
    $finallist = array();
    
    foreach($stack as $unterricht){
        $ending = intval(substr($unterricht,4,4));
        if(!($currenttime > $ending)){
            array_push($finallist,$unterricht);
        }
    }
    
    $m = 0;
    
    foreach($finallist as $linet){
        print_r(substr($linet, 0,2).":".substr($linet, 2,2)." - ".substr($linet, 4,2).":".substr($linet,6,2)."\nRaum ".substr($linet,8)."\n");
        if($m == 1){
            break;
        }
        $m++;
    }
    
    $untis->logout();
    //print_r(substr($unterricht, 0,2).":".substr($unterricht, 2,2)." - ".substr($unterricht, 4,2).":".substr($unterricht,6,2)."\nRaum ".substr($unterricht,8));
?>
