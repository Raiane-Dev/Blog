import { useState } from "react";
import { Layout, Form, Input, message, Button, Row, Upload } from 'antd';
import { HeatMapOutlined, PlusOutlined, UploadOutlined } from '@ant-design/icons';
import _Header from '../components/Header';
import _Footer from '../components/Footer';
import { MoovieProperty, MooviePattern } from "../@types/Movie";
import { AuditoriumProperty, AuditoriumPattern } from "../@types/Auditorium";

const { TextArea } = Input;

function Create(): any
{
    const [loading, setLoading] = useState(false);
    const [form] = Form.useForm();
    const [moovie, setMoovie]: any = useState<MoovieProperty>(MooviePattern);
    const [auditorium, setAuditorium]: any = useState<AuditoriumProperty>(AuditoriumPattern);

    const normFile = (e: any) => {
        if (e.file.status === 'done')
            message.success(`${e.file.name} file uploaded successfully`);
        else if (e.file.status === 'error')
            message.error(`${e.file.name} file upload failed.`);

        setMoovie({ ...moovie, banner: e.file.originFileObj })

        return e?.fileList;
    };

    const handleOk = async () => {}

    return (
        <>
            <_Header />

            <Layout className='root-content form-container'>
                <Form
                    name="basic"
                    labelCol={{ span: 8 }}
                    wrapperCol={{ span: 16 }}
                    initialValues={{ remember: true }}
                    onFinish={handleOk}
                    form={form}
                    autoComplete="off"
                >
                    <Row align='middle' justify='center' className='logo'>
                        <HeatMapOutlined />
                    </Row>
                    <Form.Item
                        name="title"
                        rules={[{ required: true, message: 'Required title!' }]}
                    >
                        <Input
                            placeholder="Title"
                            type="text"
                            onChange={(val: any) => setMoovie({ ...moovie, title: val.target.value })}
                        />
                    </Form.Item>

                    <Form.Item
                        name="duration_min"
                        rules={[{ required: true, message: 'Required duration!', type: 'number', min: 0, max: 3000 }]}
                    >
                        <Input
                            placeholder="Duration (min)"
                            type="text"
                            onChange={(val: any) => setMoovie({ ...moovie, duration_min: val.target.value })}
                        />
                    </Form.Item>
                    
                    <Form.Item
                        name="director"
                        rules={[{ required: true, message: 'Required director!' }]}
                    >
                        <Input
                            placeholder="Director"
                            type="text"
                            onChange={(val: any) => setMoovie({ ...moovie, director: val.target.value })}
                        />
                    </Form.Item>

                    <Row align='middle' justify-content='space-between' className="group">
                        <Form.Item
                            name="cast"
                            rules={[{ required: true, message: 'Required cast!' }]}
                        >
                            <Input
                                placeholder="Cast (separate by commas)"
                                type="text"
                                onChange={(val: any) => setMoovie({ ...moovie, cast: val.target.value })}
                            />
                        </Form.Item>


                        <Form.Item
                            name="banner"
                            rules={[{ required: true, message: 'Required banner!' }]}
                            getValueFromEvent={normFile}
                        >
                            <Upload name="logo" maxCount={1}>
                                <Button icon={<UploadOutlined />}>Click to upload</Button>
                            </Upload>
                        </Form.Item>
                    </Row>

                    <Form.Item
                        name="description"
                        rules={[{ required: true, message: 'Please input your description!' }]}
                    >
                        <TextArea
                            placeholder="Description"
                            rows={4}
                            onChange={(val: any) => setMoovie({ ...moovie, description: val.target.value })}
                        />
                    </Form.Item>

                    <Row align='middle' justify-content='space-between' className="group">
                        <Form.Item
                            name="name"
                            rules={[{ required: true, message: 'Required auditorium!' }]}
                        >
                            <Input
                                placeholder="Name auditorium"
                                type="text"
                                onChange={(val: any) => setAuditorium({ ...auditorium, name: val.target.value })}
                            />
                        </Form.Item>


                        <Form.Item
                            name="seats_no"
                            rules={[{ required: true, message: 'Required seats!', type: 'number', min: 0 }]}
                        >
                            <Input
                                placeholder="Seats"
                                type="text"
                                onChange={(val: any) => setAuditorium({ ...auditorium, seats_no: val.target.value })}
                            />
                        </Form.Item>
                    </Row>

                    <Button className='dark'>
                        Create
                    </Button>
                </Form>
            </Layout>

            <_Footer />
        </>
    );
};

export default Create;