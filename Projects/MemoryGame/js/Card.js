
function Card() {
    console.log('new Card');
}
    
var _p = Card.prototype;
    
_p.initialize = function (id, type, mainClass) {
    this.id = id;
    this.type = type;
    this.mainClass = mainClass;

    var parentEl = document.getElementById('cards'), cardEl;
    

    this.cardEl = document.createElement('div');
    this.cardEl.id = 'Card' + id;
    this.cardEl.className = 'Card';

    var that = this;
    this.cardEl.ontouchstart = function(event) {//for iOS
        that.onItemClick();
    };
    this.cardEl.onmouseup = function(event) {//for all others
        that.onItemClick();
    };

    var x = (73 * type) % ( 73 * 13);
    this.cardValue = x / 13;
    var y = Math.floor((73 * type) / ( 73 * 13)) * 98;
    this.cardEl.style.backgroundPosition = x + "px " + y + "px" ; 
    
    
    this.cardBgEl = document.createElement('div');
    this.cardBgEl.id = 'CardBg' + id;
    this.cardBgEl.className = 'CardBg';
    this.cardEl.appendChild(this.cardBgEl);
    
    parentEl.appendChild(this.cardEl);
        
};

_p.getCardValue = function() {
    return this.cardValue;
};

_p.getType = function() {
    return this.type;
};

_p.hide = function() {
    this.cardEl.style.visibility = 'hidden';
};

_p.open = function() {
    this.cardBgEl.style.visibility = 'hidden';
};

_p.close = function() {
    this.cardBgEl.style.visibility = 'visible';
};


_p.onItemClick = function() {
    this.mainClass.onItemClick(this);
};
    
_p.clear = function() {
    console.log('Card:clear 1');
    this.cardEl.parentNode.removeChild(this.cardEl);
    console.log('Card:clear 2');
};