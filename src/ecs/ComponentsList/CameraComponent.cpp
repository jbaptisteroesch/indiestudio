//
// Created by jbroesch on 5/31/21.
//

#include "CameraComponent.hpp"
#include "../../graphicalLib/IGraphic.hpp"

/*
        {"name": "cameraComponent",
            "positionX": 0, "positionY": 1.5, "positionZ": 3.0,
            "targetX": 0, "targetY": 1.5, "targetZ": 0,
            "upX": 0, "upY": 1.0, "upZ": 0,
            "fovy": 45.0
        },*/
namespace Indie {

    CameraComponent::CameraComponent(Json::Value &values) {
        _values = values;
    }

    void CameraComponent::init(IGraphic *libgraphic) {
        _camera = libgraphic->create_camera();
        float positionx = _values["positionX"].asFloat();
        float positiony = _values["positionY"].asFloat();
        float positionz = _values["positionZ"].asFloat();
        _camera->setRaylibCameraPosition(positionx, positiony, positionz);
        float targetx = _values["targetX"].asFloat();
        float targety = _values["targetY"].asFloat();
        float targetz = _values["targetZ"].asFloat();
        _camera->setRaylibCameraTarget(targetx, targety, targetz);
        float upx = _values["upX"].asFloat();
        float upy = _values["upY"].asFloat();
        float upz = _values["upZ"].asFloat();
        _camera->setRaylibCameraUp(upx, upy, upz);
        float fovy = _values["fovy"].asFloat();
        _camera->setRaylibCameraFovy(fovy);
        _camera->setRaylibCameraMode();
        libgraphic->set_camera(*this);
    }

    void CameraComponent::update(double time) {
        (void)time;
    }

    ICamera &CameraComponent::getCamera() {
        return *_camera;
    }
}