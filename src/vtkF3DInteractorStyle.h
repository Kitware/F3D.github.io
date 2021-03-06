/**
 * @class   vtkF3DInteractorStyle
 * @brief   custom interactor style based on default trackball camera
 */

#ifndef vtkF3DInteractorStyle_h
#define vtkF3DInteractorStyle_h

#include <vtkInteractorStyleTrackballCamera.h>

class F3DAnimationManager;
struct F3DOptions;

class vtkF3DInteractorStyle : public vtkInteractorStyleTrackballCamera
{
public:
  static vtkF3DInteractorStyle* New();
  vtkTypeMacro(vtkF3DInteractorStyle, vtkInteractorStyleTrackballCamera);

  /**
   * Handle key presses
   */
  void OnKeyPress() override;

  /**
   * Disable base class features
   */
  void OnChar() override {}

  /**
   * Disable base class features
   */
  void OnTimer() override {}

  /**
   * Handle drop files
   */
  void OnDropFiles(vtkStringArray* files) override;

  /**
   * Overriden for turntable mode
   */
  void Rotate() override;

  //@{
  /**
   * Overriden to disable during animation
   */
  void Spin() override;
  void Pan() override;
  void Dolly() override;
  //@}

  /**
   * Overriden to rotate the skybox as well
   */
  void EnvironmentRotate() override;

  /**
   * Set animation manager
   */
  void SetAnimationManager(const F3DAnimationManager& mgr) { this->AnimationManager = &mgr; };

  /**
   * Set options
   */
  void SetOptions(const F3DOptions& options) { this->Options = &options; };

protected:
  /**
   * Overriden to disable during animation
   */
  void Dolly(double factor) override;

  virtual bool IsUserInteractionBlocked();

  const F3DAnimationManager* AnimationManager = nullptr;
  const F3DOptions* Options = nullptr;
};

#endif
