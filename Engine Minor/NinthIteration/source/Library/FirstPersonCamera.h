#pragma once

#include "Camera.h"

namespace Library
{
    class Keyboard;
    class Mouse;

    class FirstPersonCamera : public Camera
    {
        RTTI_DECLARATIONS(FirstPersonCamera, Camera)

    public:
        FirstPersonCamera(Game& game);
        FirstPersonCamera(Game& game, float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance);

        virtual ~FirstPersonCamera();

        const Keyboard& GetKeyboard() const;
        void SetKeyboard(Keyboard& keyboard);

        const Mouse& GetMouse() const;
        void SetMouse(Mouse& mouse);

		float& RotationRate();
        float& MouseSensitivity();
        float& MovementRate();		
        
        virtual void Initialize() override;
        virtual void Update(const GameTime& gameTime) override;

        static const float MouseSpeed;
        static const float RotationSpeed;
        static const float MovementSpeed;        

    protected:
        float mMouseSensitivity;
        float mRotationRate;
        float mMovementRate;        

		Keyboard* mKeyboard;
        Mouse* mMouse;

    private:
        FirstPersonCamera(const FirstPersonCamera& rhs);
        FirstPersonCamera& operator=(const FirstPersonCamera& rhs);
    };
}

