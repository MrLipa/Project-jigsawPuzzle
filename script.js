var centiseconds=0;
var seconds=0;
var minutes=0;
var timer;
function display(minutes, seconds, centiseconds) {
    if (centiseconds < 10) {
    centiseconds = "0" + centiseconds.toString();
    } else {
    centiseconds = centiseconds.toString();
    }
    if (seconds < 10) {
    seconds = "0" + seconds.toString();
    } else {
    seconds = seconds.toString();
    }
    if (minutes < 10) {
    minutes = "0" + minutes.toString();
    } else {
    minutes = minutes.toString();
    }
    document.getElementById("timer").innerHTML = minutes + ":" + seconds + "." + centiseconds;
}
function check() {
    if(document.getElementById('pauza/kontynuacja').value=="kontynuacja")
    {
        document.getElementById('pauza/kontynuacja').value = "pauza";
        if(timer==null)
        {
            if (window.Worker) {
                timer = new Worker("timer.js");
                timer.postMessage({
                centiseconds: centiseconds,
                seconds: seconds,
                minutes: minutes,
                });
                timer.onmessage = function (e) {
                centiseconds = e.data.centiseconds;
                seconds = e.data.seconds;
                minutes = e.data.minutes;
                display(minutes, seconds, centiseconds);
                };
            }
        }
    }
    else
    {
        document.getElementById('pauza/kontynuacja').value = "kontynuacja";
        if(timer)
        {
            timer.terminate();
            timer=null;
        }
    }
}
function change(value)
{
    var NavY = $('.nav').offset().top;
        
    var stickyNav = function(){
    var ScrollY = $(window).scrollTop();
            
    if (ScrollY > NavY && value!='content4') { 
        $('.nav').addClass('sticky');
    }else if(value=='content4') {
        $('.nav').removeClass('sticky'); 
    }
    else {
        $('.nav').removeClass('sticky'); 
    }
    };
        
    stickyNav();
        
    $(window).scroll(function() {
        stickyNav();
    });
    document.getElementById('content1').style.display="none";
    document.getElementById('content2').style.display="none";
    document.getElementById('content3').style.display="none";
    document.getElementById('content4').style.display="none";

    document.getElementById(value).style.display="block";
}
function zero(name)
{
    document.getElementById(name+"_x").value=0;
    document.getElementById(name+"_y").value=0;
    update('velocity_rick_x');
    update('velocity_rick_y');
    update('velocity_morty_x');
    update('velocity_morty_y');
}
function update(name)
{
    if(name='velocity_rick_x')
    {
        document.getElementById('vz_x').innerHTML="Predkosc zrodla: "+document.getElementById(name).value+" [m/s]";
    }
    if(name='velocity_morty_x')
    {
        document.getElementById('vo_x').innerHTML="Predkosc odbiornika: "+document.getElementById(name).value+" [m/s]";
    }
    if(name='velocity_rick_y')
    {
        document.getElementById('vz_y').innerHTML="Predkosc zrodla: "+document.getElementById(name).value+" [m/s]";
    }
    if(name='velocity_morty_y')
    {
        document.getElementById('vo_y').innerHTML="Predkosc odbiornika: "+document.getElementById(name).value+" [m/s]";
    }
    if(name='frequency')
    {
        document.getElementById('f').innerHTML="Czestotliwosc: "+document.getElementById(name).value/100+" [Hz]";
        document.getElementById('f_z').innerHTML="Sygnal jaki wysyla Rick Sanchez "+document.getElementById('frequency').value/100+" [Hz]";
    }
}


function start() {
    var canvas = document.getElementById("canvas");
    var context = canvas.getContext("2d");

    var canvas1 = document.getElementById("canvas1");
    var context1 = canvas1.getContext("2d");

    var canvas2 = document.getElementById("canvas2");
    var context2 = canvas2.getContext("2d");

    end();
    if(timer)
    {
        timer.terminate();
        timer=null;
        centiseconds = 0;
        seconds = 0;
        minutes = 0;
    }
    if(timer==null)
    {
        if (window.Worker) {
            timer = new Worker("timer.js");
            timer.postMessage({
            centiseconds: centiseconds,
            seconds: seconds,
            minutes: minutes,
            });
            timer.onmessage = function (e) {
            centiseconds = e.data.centiseconds;
            seconds = e.data.seconds;
            minutes = e.data.minutes;
            display(minutes, seconds, centiseconds);
            };
        }
    }

    var img = new Image(); 
    var iter=0;
    var prev=0;
    var circles=[];
    var acceleration=8;
    var speed_of_sound=340;
    var velocity_wave=2;
    var wave_long=450;
    var stop=0;
    var prev_dist=0;
    var line=15;

    var position_rick_x=150;
    var position_morty_x=300;
    var position_rick_y=200;
    var position_morty_y=200;

    var time_animation=20;
    var start_time=window.performance.now()/1000;
    var prev_time=window.performance.now()/1000;
    var prev_time1=window.performance.now()/1000;

    document.getElementById("koniec").addEventListener("click", function() {   
        stop=1;
        if(timer)
        {
            timer.terminate();
            timer=null;
            centiseconds = 0;
            seconds = 0;
            minutes = 0;
            display(minutes, seconds, centiseconds);
        }

      });
    document.getElementById("start").addEventListener("click", function() {     
        stop=1;
      });
    
    function key_fun(evt) 
    {
        switch(evt.keyCode) 
        {
            case 87:
                document.getElementById("velocity_rick_y").value=parseInt(document.getElementById("velocity_rick_y").value)-acceleration;
                update('velocity_rick_x');
                update('velocity_rick_y');
                break;
            case 68:
                document.getElementById("velocity_rick_x").value=parseInt(document.getElementById("velocity_rick_x").value)+acceleration;
                update('velocity_rick_x');
                update('velocity_rick_y');
                break;
            case 83:
                document.getElementById("velocity_rick_y").value=parseInt(document.getElementById("velocity_rick_y").value)+acceleration;
                update('velocity_rick_x');
                update('velocity_rick_y');
                break;
            case 65:
                document.getElementById("velocity_rick_x").value=parseInt(document.getElementById("velocity_rick_x").value)-acceleration;
                update('velocity_rick_x');
                update('velocity_rick_y');
                break;
            case 38:
                document.getElementById("velocity_morty_y").value=parseInt(document.getElementById("velocity_morty_y").value)-acceleration;
                evt.preventDefault();
                update('velocity_morty_x');
                update('velocity_morty_y');
                break;
            case 39:
                document.getElementById("velocity_morty_x").value=parseInt(document.getElementById("velocity_morty_x").value)+acceleration;
                update('velocity_morty_x');
                update('velocity_morty_y');
                break;
            case 37:
                document.getElementById("velocity_morty_x").value=parseInt(document.getElementById("velocity_morty_x").value)-acceleration;
                update('velocity_morty_x');
                update('velocity_morty_y');
                break;
            case 40:
                document.getElementById("velocity_morty_y").value=parseInt(document.getElementById("velocity_morty_y").value)+acceleration;
                evt.preventDefault();
                update('velocity_morty_x');
                update('velocity_morty_y');
                break;
        }
    }

    function end()
    {
        context.beginPath();
        context1.beginPath();
        context2.beginPath();
        context.clearRect(0, 0, canvas.width, canvas.height);
        context1.clearRect(0, 0, canvas1.width, canvas1.height);
        context2.clearRect(0, 0, canvas2.width, canvas2.height);
    }
    
    function draw()
    {
        if(stop==1)
        {
            end()
            return;
        }
        if(document.getElementById('pauza/kontynuacja').value=="pauza")
        {
            var velocity_rick_x=(velocity_wave/speed_of_sound)*document.getElementById("velocity_rick_x").value;
            var velocity_morty_x=(velocity_wave/speed_of_sound)*document.getElementById("velocity_morty_x").value;

            var velocity_rick_y=(velocity_wave/speed_of_sound)*document.getElementById("velocity_rick_y").value;
            var velocity_morty_y=(velocity_wave/speed_of_sound)*document.getElementById("velocity_morty_y").value;

            frequency=1/(document.getElementById("frequency").value/100);

            context.clearRect(0, 0, canvas.width, canvas.height);

            document.addEventListener("keydown", key_fun);

            function calculate()
            {
                var dist=Math.sqrt(Math.pow(position_rick_x-position_morty_x,2)+Math.pow(position_rick_y-position_morty_y,2));
                if( prev_dist-dist>0 )
                {
                    prev_dist=dist;
                    return Math.round((1/frequency) * ( (340+Math.abs(Math.sqrt(Math.pow(velocity_morty_x,2)+Math.pow(velocity_morty_y,2))*(speed_of_sound/velocity_wave))) / (340-Math.abs(Math.sqrt(Math.pow(velocity_rick_x,2)+Math.pow(velocity_rick_y,2))*(speed_of_sound/velocity_wave))) ) * 100) / 100;
                }
                else
                {
                    prev_dist=dist;
                    return  Math.round((1/frequency) * ( (340-Math.abs(Math.sqrt(Math.pow(velocity_morty_x,2)+Math.pow(velocity_morty_y,2))*(speed_of_sound/velocity_wave))) / (340+Math.abs(Math.sqrt(Math.pow(velocity_rick_x,2)+Math.pow(velocity_rick_y,2))*(speed_of_sound/velocity_wave))) ) * 100) / 100;
                }
            }
            
            document.getElementById('f_o').innerHTML="Sygnal jaki odbiera Morty Smith "+calculate()+" [Hz]";

            for (var circle of circles) {
                context.beginPath();
                context.arc(circle.x,circle.y, circle.r+=velocity_wave, 0, 2 * Math.PI);

                if(Math.abs(Math.sqrt(Math.pow(position_morty_x-circle.x,2)+Math.pow(position_morty_y-circle.y,2))-circle.r)<=velocity_wave)
                {
                    if(iter!=prev+1)
                    {
                        context2.moveTo(10, line);
                        context2.lineTo(70, line);
                    }
                    prev=iter;
                }
                context.strokeStyle = 'red';
                context.stroke();
                context1.strokeStyle = "red";
                context1.stroke();
                context2.strokeStyle = "blue";
                context2.stroke();
            }

            if(window.performance.now()/1000-prev_time>=frequency)
            {
                circles.push({x:position_rick_x,y:position_rick_y,r:20});
                context1.moveTo(10, line);
                context1.lineTo(70, line);
                prev_time=window.performance.now()/1000;
            }
            if(iter==0)
            {
                circles.push({x:position_rick_x,y:position_rick_y,r:20});
                context1.moveTo(10, line);
                context1.lineTo(70, line);
            }
            circles=circles.filter(function(value){return value.r<=wave_long;});
            if(window.performance.now()/1000-prev_time1>=0.1)
            { 
                prev_time1=window.performance.now()/1000;
                line+=2;
            }
            img.src = 'rick.png';
            context.drawImage(img,position_rick_x-15,position_rick_y-15,30,30);
            img.src = 'morty.png';
            context.drawImage(img,position_morty_x-15,position_morty_y-15,30,30);
            
            iter+=1;

            position_rick_x+=velocity_rick_x;
            position_morty_x+=velocity_morty_x;

            position_rick_y+=velocity_rick_y;
            position_morty_y+=velocity_morty_y;

            // if(window.performance.now()/1000-start_time<=time_animation)
            // {
            //     requestAnimationFrame(draw);
            // }

            if(line<=parseInt(document.getElementById("canvas1").height)-15)
            {
                requestAnimationFrame(draw);
            }
            else
            {
                if(timer)
                {
                    timer.terminate();
                    timer=null;
                    centiseconds = 0;
                    seconds = 0;
                    minutes = 0;
                }
            }
        }
        else
        {
            requestAnimationFrame(draw);
        }
    }
    draw();
}