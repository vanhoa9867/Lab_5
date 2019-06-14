// POSITION TO RGB MAPPING: FRAGMENT SHADER 
varying vec4 color; // gia tri mau da tinh tu vertex shader 
void main() { 
    // gan gia tri mau nay cho pixel 
    gl_FragColor = color; 
} 