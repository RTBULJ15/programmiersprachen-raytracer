
Camera()
{

}

Camera(std::string name,double horizontal_apex_angle, glm::ivec2 resolution)
{

}

void setname(std::string name)
{
    name_ = name;
}

void setangle(double angle)
{
    horizontal_apex_angle = angle;
}

void setResolution_x(double resx)
{
    resolution.x = resx;
}

void setResolution_y(double resy)
{
    resolution.y = resy;
}
