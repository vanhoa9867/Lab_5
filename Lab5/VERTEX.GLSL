
varying vec4 color; //gia tri mau dung cho fragment shader 
void main() { 
    // chuan hoa toa do dinh anh xa vao khong gian gian RGB 
    color = (normalize(gl_Vertex.zyxw) + vec4(0.5, 0.5, 0.5, 1.0)); 
    // tinh toa do chieu cho moi dinh 
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; 
}