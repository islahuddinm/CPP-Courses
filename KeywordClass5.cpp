#include <iostream>


// A simplified example of Unreal Engine's FRotator class
struct FRotator {
    float Pitch;
    float Yaw;
    float Roll;

    FRotator(float InPitch = 0.0f, float InYaw = 0.0f, float InRoll = 0.0f)
        : Pitch(InPitch), Yaw(InYaw), Roll(InRoll) {}
};


// A simplified example of Unreal Engine's ACharacter class
class ACharacter {
public:
    // The movement component of the character
    class UCharacterMovementComponent {
    public:
        bool bOrientRotationToMovement;
        FRotator RotationRate;
        float JumpZVelocity;
        float AirControl;
    };

    // Method to get the movement component (simulating Unreal Engine's API)
    UCharacterMovementComponent* GetCharacterMovement() {
        return &CharacterMovement;
    }

private:
    UCharacterMovementComponent CharacterMovement;
};


// MyCharacter class inheriting from ACharacter
class MyCharacter : public ACharacter {
public:
    void SetupMovement() {
        // Setting up movement properties
        GetCharacterMovement()->bOrientRotationToMovement = true;
        GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
        GetCharacterMovement()->JumpZVelocity = 600.0f;
        GetCharacterMovement()->AirControl = 0.2f;
    }
};


// Simulated main function (Note: Unreal Engine does not use main())
int main() {
    // Create an instance of MyCharacter
    MyCharacter MyChar;

    // Set up movement properties for the character
    MyChar.SetupMovement();

    // Output the configured values to verify
    ACharacter::UCharacterMovementComponent* MovementComp = MyChar.GetCharacterMovement();
    std::cout << "bOrientRotationToMovement: " << MovementComp->bOrientRotationToMovement << std::endl;
    std::cout << "RotationRate (Yaw): " << MovementComp->RotationRate.Yaw << std::endl;
    std::cout << "JumpZVelocity: " << MovementComp->JumpZVelocity << std::endl;
    std::cout << "AirControl: " << MovementComp->AirControl << std::endl;

    return 0;
}
