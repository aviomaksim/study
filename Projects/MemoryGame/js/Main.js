function startGame( )
{
    console.log('Main:myFunction');

    

    //document.getElementById("lobby").style.display = 'none';
    document.getElementById("game").style.display = 'inherit';
        
    var sizeCombo = document.getElementById("cardsCountCombo");
    var cardsCount = parseInt(sizeCombo.options[sizeCombo.selectedIndex].value);
    
    var levelCombo = document.getElementById("levelCombo");
    var level = parseInt(levelCombo.options[levelCombo.selectedIndex].value);

    if (this.g) {
        this.datas[this.datas.length] = this.g.getData();
        this.g.clear();
        this.g = null;
    } else {
        this.datas = [];
    }
    this.g = new Main();
    this.g.initialize(this.datas.length, cardsCount, level );
}

function showHistory( )
{
    console.log('Main:showHistory');
    if (this.g) {
        if (this.datas.length>0) {
            if (this.g.getData().id != this.datas[this.datas.length - 1].id) {
                this.datas[this.datas.length] = this.g.getData();
            }
        } else {
            this.datas[this.datas.length] = this.g.getData();
        }
    }
    
    var myWindow=window.open('','','width=400,height=800');
    myWindow.document.write("<p>Ajalugu</p><br>");
    var text  = '<table border=\"2\">';
    text = text + '<tr><td>ID</td><td>Aeg</td><td>Miinuspunktid</td><td>level</td><td>Suurus</td><td>Kas voitsid</td></tr>';
    for (var i = 0; i < this.datas.length; i++) {
        text = text + '<tr><td>' + this.datas[i].id + '</td><td>' + this.datas[i].time + '</td><td>' + this.datas[i].points + '</td><td>' + this.datas[i].level + '</td><td>'+ this.datas[i].size + '</td><td>'+ this.datas[i].ended + '</td></tr>';
    }
    text = text + '</table>';
    
    myWindow.document.write(text);
    myWindow.focus();
}

function levelChanged( )
{
    console.log('Main:levelChanged');
    var sizeCombo = document.getElementById("cardsCountCombo");
    var cardsCount = parseInt(sizeCombo.options[sizeCombo.selectedIndex].value);
    
    var levelCombo = document.getElementById("levelCombo");
    var level = parseInt(levelCombo.options[levelCombo.selectedIndex].value);
    
    if(level<1 && cardsCount>51) {
        sizeCombo.value = 26;
        alert('NB! Pakk on muutnud!');
    }
}

function packChanged( )
{
    console.log('Main:packChanged');
    var levelCombo = document.getElementById("levelCombo");
    var level = parseInt(levelCombo.options[levelCombo.selectedIndex].value);
    
    var sizeCombo = document.getElementById("cardsCountCombo");
    var cardsCount = parseInt(sizeCombo.options[sizeCombo.selectedIndex].value);
    
    if(level<1 && cardsCount>51) {
        levelCombo.value = 1;
        alert('NB! Raskus on muutnud!');
    }
}

function Main() {
    //document.getElementById("demo").innerHTML = "Hello word";
}

var _p = Main.prototype;

_p.initialize = function (gameCount, cardsCount, level) {
    console.log('Main:initialize');
    this.cardsCount = cardsCount;
    this.level = level;
    this.cardsOpen = 0;
    
    this.data = {
       id: gameCount,
       time: 0,
       points: 0,
       level: level,
       size: cardsCount,
       ended: "Ei ole"
    };

    document.getElementById('cards').className  = 's' + cardsCount;

    this.preload('img/classic-playing-cards.png');

    this.cards = [];
    this.point = 0;
    document.getElementById("info").innerHTML="Miinuspunkt! Punktid kokku: " + this.point;

    var countOfImages = 52;
    var activeImages = [];
    var pack = [];
    for (i = 0; i < countOfImages; i++) {
        pack[i] = i;
    }

    var randomnumber;
    for (i = 0; i < this.cardsCount/2; i++) {
        randomnumber = Math.floor(Math.random() * pack.length);
        activeImages[i] = pack[randomnumber];
        activeImages[i + this.cardsCount/2] = pack[randomnumber];
        
        pack.splice(randomnumber, 1);//remove from array
    }

    var i, type;


    for (i = 0; i < this.cardsCount; i++) {
        randomnumber = Math.floor(Math.random() * activeImages.length);
        type = activeImages[randomnumber];
        activeImages.splice(randomnumber, 1);//remove from array


        this.cards[i] = new Card();
        this.cards[i].initialize(i, type, this);
    }

    this.gameSecs = 0;
    document.getElementById("clock").innerHTML="Aeg labi: " + this.gameSecs + " sekund";
    var that = this;
    this.gameTimer = setInterval(function() {
        that.gameSecs++;
        document.getElementById("clock").innerHTML="Aeg labi: " + that.gameSecs + " sekund";
    }, 1000);
};

_p.onItemClick = function (itemClass) {
    console.log('Main:onItemClick ' + this.locked);

    if (!this.locked) {

        //this.locked = true;

        if (this.timer) {
            clearTimeout(this.timer);
            this.timer = null;

            if (this.timerCallback) this.timerCallback.call(this);
        }
        this.timerCallback = null;

        itemClass.open();

        var that = this;
        if (this.openedItem == null) {
            this.openedItem = itemClass;
            //this.locked = false;
        } else if ( this.level === 1 && this.openedItem.getType() === itemClass.getType() 
            || this.level === 0 && this.openedItem.getCardValue() === itemClass.getCardValue()) {
            this.cardsOpen += 2;

            console.log('won: this.cardsOpen='+this.cardsOpen+' this.cardsCount='+this.cardsCount);
            if(this.cardsCount === this.cardsOpen) {
                clearTimeout(this.gameTimer);
                this.gameTimer = null;

                this.data.points = this.point;
                this.data.time = this.gameSecs;
                this.data.ended = "Jah";
                
                this.showCongratulation();
            }
            
            this.openedItem2 = itemClass;
            this.timerCallback = this.wonPoint;
            this.timer = setTimeout(function () {
                that.openedItem.hide();
                that.openedItem = null;
                if (that.openedItem2) {
                    that.openedItem2.hide();
                    that.openedItem2 = null;
                }
            }, 1000);
        } else { //lose
            this.point--;
            document.getElementById("info").innerHTML="Miinuspunkt! Punktid kokku: " + this.point;
            
            this.openedItem2 = itemClass;
            this.timerCallback = this.losePoint;
            this.timer = setTimeout(function () {
                that.openedItem.close();
                that.openedItem = null;
                if (that.openedItem2) {
                    that.openedItem2.close();
                    that.openedItem2 = null;
                }
            }, 2000);
        }
    }
};

_p.showCongratulation = function () {
    console.log('Main:showCongratulation');
    
    var myWindow=window.open('','','width=200,height=100');
    myWindow.document.write("<p>Palju onne!!! Mang on labi. Proovi uuesti.</p><br>");
    var text  = '<table border=\"2\">';
    text = text + '<tr><td>ID</td><td>Aeg</td><td>Miinuspunktid</td><td>level</td><td>Suurus</td></tr>';
    text = text + '<tr><td>' + this.data.id + '</td><td>' + this.data.time + '</td><td>' + this.data.points + '</td><td>' + this.data.level + '</td><td>'+ this.data.size + '</td></tr>';

    text = text + '</table>';
    
    myWindow.document.write(text);
    myWindow.focus();
};

_p.wonPoint = function () {
    console.log('wonPoint');
    if (this.timerCallback) this.timerCallback = null;
    if (this.openedItem) {
        this.openedItem.hide();
        this.openedItem = null;
    }
    if (this.openedItem2) {
        this.openedItem2.hide();
        this.openedItem2 = null;
    }
};

_p.losePoint = function () {
    console.log('losePoint');
    if (this.timerCallback) this.timerCallback = null;
    if (this.openedItem) {
        this.openedItem.close();
        this.openedItem = null;
    }
    if (this.openedItem2) {
        this.openedItem2.close();
        this.openedItem2 = null;
    }
};


_p.preload = function(images) {
    if (document.images) {
        var i = 0;
        var imageArray = new Array();
        imageArray = images.split(',');
        var imageObj = new Image();
        for (i = 0; i <= imageArray.length - 1; i++) {
            //document.write('<img src="' + imageArray[i] + '" />');// Write to page (uncomment to check images)
            imageObj.src = imageArray[i];
        }
    }
};

_p.getData = function() {
    return this.data;
};

_p.saved = function() {
    if( this.gameTimer ) {
        return false; 
    } else {
        return true;
    }
};

_p.clear = function () {
    console.log('Main:clear 1');
    for (var i = 0; i < this.cards.length; i++) {
        this.cards[i].clear();
        this.cards[i] = null;
    }
    if (this.timer) {
        clearTimeout(this.timer);
        this.timer = null;
    }
    if (this.timerCallback) this.timerCallback = null;
    if (this.gameTimer) {
        clearTimeout(this.gameTimer);
        this.gameTimer = null;
    }

    this.data.points = this.point;
    this.data.time = this.gameSecs;
    console.log('Main:clear 2');
};

