

struct Attribute{
    float4 pos:POSITION;
};


float4 vert(Attribute attr)  {
    return attr.pos;
}
