cbuffer test{
    float4x4 modelMatrix;
    float4x4 viewMatrix;
    float4x4 projectionMatrix;
}


struct Attribute{
    float4 pos:POSITION;
    float3 color:COLOR;
};


float4 vert(Attribute attr)  {
    float4 world = mul(modelMatrix, attr.pos);
    float4 viewPos = mul(viewMatrix, world);
    return mul(projectionMatrix, viewPos);
}
