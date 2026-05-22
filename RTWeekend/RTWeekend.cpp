// RTWeekend.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "rtweekend.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"

int main()
{
    // Filestream
    
    std::ofstream outf{ "image.ppm" };

    if (!outf)
    {
        std::cerr << "Error writing to image.ppm\n";
        return 1;
    }

    // World
    
    hittable_list world{};

    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    camera cam{};
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;

    cam.render(world, outf);

    return 0;
}